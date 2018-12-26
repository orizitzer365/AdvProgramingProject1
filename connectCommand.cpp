//
// Created by ori on 12/26/18.
//
#include "connectCommand.h"
connectCommand::connectCommand(SymbolTable *v, map <string, string> *bi, bool *run) :stillRun(run),vars(v) {
    vars = v;
    bindingMap=bi;
    calc=new Calculator(vars);
}

int connectCommand::doCommand(vector <vector<string>> strings) {
    vector<string> param = strings.at(0);
    if(param.size()!=3)
        throw "not enough arguments";
    int port = calc->calculate(param.at(2));
    thread client(&connectCommand::serverConnct,this,port,param.at(1));
    client.detach();
    return 1;
}

void connectCommand::serverConnct(int port, string ip) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
//        while (vars->size()==0){}
    string buffer = "";
    portno = port;

    /* Create a socket point */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(ip.c_str());

    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    /* Now connect to the server */
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }
    this->socket_id = sockfd;
    /* Send message to the server */
    while(true){

        for(auto& binds : *bindingMap){
            buffer="";
            buffer= "set " + binds.second + " " + to_string((vars->at(binds.second))->calculate()) + "\n";
            n = ::send(sockfd,buffer.c_str(), buffer.size(),0);
            if (n < 0) {
                perror("ERROR writing to socket");
                exit(1);
            }
        }

    }
    close(sockfd);
}

connectCommand::~connectCommand() {
    close(socket_id);
}

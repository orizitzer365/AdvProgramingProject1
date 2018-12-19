//
// Created by ori on 12/17/18.
//

#ifndef PROJECT1_CONECTCOMMAND_H
#define PROJECT1_CONECTCOMMAND_H
#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string.h>

#include <sys/socket.h>
#include <map>
#include <thread>
#include "Expression.h"
#include "Command.h"
class conectCommand:public Command{
private:
    map<string,double > vars;
    map<string,string > bindingMap;
public:
    conectCommand(map<string, double> &v,    map<string,string > bi){
        vars =v;
        bindingMap=bi;
    }

    int doCommand(vector<string> param) override {
        int port = stoi(param.at(1));
        thread server(&conectCommand::serverConnct,port,param.at(2));
        server.join();
        return 2;
    }

    void serverConnct(int port ,string ip){
        int sockfd, portno, n;
        struct sockaddr_in serv_addr;
        struct hostent *server;

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
        if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
            perror("ERROR connecting");
            exit(1);
        }

        /* Now ask for a message from the user, this message
           * will be read by server
        */

        /* Send message to the server */
        while(true){
            for(const auto& binds : bindingMap){
                buffer="set "+binds.second+to_string(vars.at(binds.first));
                n = write(sockfd,buffer, strlen(buffer));

                if (n < 0) {
                    perror("ERROR writing to socket");
                    exit(1);
                }

                /* Now read server response */
                buffer="";
                n = read(sockfd, buffer.c_str(), 255,1);

                if (n < 0) {
                    perror("ERROR reading from socket");
                    exit(1);
                }
                vars.at(binds.first)=stod(buffer);
            }

        }

    }
};
#endif //PROJECT1_CONECTCOMMAND_H

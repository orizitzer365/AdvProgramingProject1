//
// Created by ori on 12/17/18.
//
#ifndef PROJECT1_OPENDATASERVERCOMMAND_H
#define PROJECT1_OPENDATASERVERCOMMAND_H
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
class openDataServerCommand:public Command{
private:
    map<string,double > vars;
    map<string,string > bindingMap;
public:
    openDataServerCommand(map<string, double> &v,    map<string,string >& bi){
        vars =v;
        bindingMap=bi;
    }

    void serverOpen(int port ,int Hz){
        int sockfd, newsockfd, portno, clilen;
        string buffer;
        struct sockaddr_in serv_addr, cli_addr;
        int  n;

        /* First call to socket() function */
        sockfd = socket(AF_INET, SOCK_STREAM, 0);

        if (sockfd < 0) {
            perror("ERROR opening socket");
            exit(1);
        }

        /* Initialize socket structure */
        bzero((char *) &serv_addr, sizeof(serv_addr));
        portno = port;

        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = INADDR_ANY;
        serv_addr.sin_port = htons(portno);

        /* Now bind the host address using bind() call.*/
        if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
            perror("ERROR on binding");
            exit(1);
        }

        /* Now start listening for the clients, here process will
           * go in sleep mode and will wait for the incoming connection
        */

        listen(sockfd,5);
        clilen = sizeof(cli_addr);

        /* Accept actual connection from the client */
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);

        if (newsockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        /* If connection is established then start communicating */
       while (true){
           for(const auto& binds : bindingMap){
               buffer="set "+binds.second+to_string(vars.at(binds.first));
               n = write(newsockfd,buffer.c_str(),strlen(buffer.c_str()));

               if (n < 0) {
                   perror("ERROR reading from socket");
                   exit(1);
               }

               /* Write a response to the client */

               n = read(newsockfd,"I got your message",18);

               if (n < 0) {
                   perror("ERROR writing to socket");
                   exit(1);
               }
           }

       }
    }

    int doCommand(vector<string> param) override {
        int port = stoi(param.at(1));
        int Hz = stoi(param.at(2));
        thread server(&openDataServerCommand::serverOpen,port,Hz);
        server.join();
        return 3;
    }

};

int read(int socketid, string& out, int bytes) {
    out.resize(bytes);
    read(socketid, &out[0], bytes);
}
#endif //PROJECT1_OPENDATASERVERCOMMAND_H

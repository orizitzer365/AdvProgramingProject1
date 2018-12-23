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
#include "Var.h"
#include "SymbolTable.h"
void installVals(vector<string> &simVals);
int read(int socketid, string& out, int bytes) ;
class openDataServerCommand:public Command{
private:
    SymbolTable vars;
    vector<string> simValues;
    Calculator calc;
public:
    openDataServerCommand(SymbolTable &v, Calculator &c):calc(c) {
        vars = v;
        installVals(simValues);
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
           buffer="";
           n = read(newsockfd,buffer,400);

           if (n < 0) {
               perror("ERROR reading from socket");
               exit(1);
           }
           installValuesFromSim(buffer);



           sleep(10000/Hz);
       }
    }
    void installValuesFromSim(string line){
        string name ="";
        string val = "";
        int i=0;

        for (int j = 0; j < 23; ++j) {
            name = simValues.at(j);
            val = "";
            while (line.at(i)!=','||line.at(i)!='\0')
                val+=line.at(i);
            i++;
            if(!vars.exists(name)){
                vars.add(name,stod(val));
            } else
                vars.at(name)->setValue(stod(val));
        }
    }

    int doCommand(vector<vector<string>> strings) override {
        vector<string> param = strings.at(0);
        if(param.size()!=3)
            throw "invalid parmameters";
        int port = calc.calculate(param.at(1));
        int Hz = calc.calculate(param.at(2));
        thread server(&openDataServerCommand::serverOpen,port,Hz);
        server.join();
        return 1;
    }

};
void installVals(vector<string> &simVals){
    simVals.push_back("/instrumentation/airspeed-indicator/indicated-speed-kt");
    simVals.push_back("/instrumentation/altimeter/indicated-altitude-ft");
    simVals.push_back("/instrumentation/altimeter/pressure-alt-ft");
    simVals.push_back("/instrumentation/attitude-indicator/indicated-pitch-deg");
    simVals.push_back("/instrumentation/attitude-indicator/indicated-roll-deg");
    simVals.push_back("/instrumentation/attitude-indicator/internal-pitch-deg");
    simVals.push_back("/instrumentation/attitude-indicator/internal-roll-deg");
    simVals.push_back("/instrumentation/encoder/indicated-altitude-ft");
    simVals.push_back("/instrumentation/encoder/pressure-alt-ft");
    simVals.push_back("/instrumentation/gps/indicated-altitude-ft");
    simVals.push_back("/instrumentation/gps/indicated-ground-speed-kt");
    simVals.push_back("/instrumentation/gps/indicated-vertical-speed");
    simVals.push_back("/instrumentation/heading-indicator/indicated-heading-deg");
    simVals.push_back("/instrumentation/magnetic-compass/indicated-heading-deg");
    simVals.push_back("/instrumentation/slip-skid-ball/indicated-slip-skid");
    simVals.push_back("/instrumentation/turn-indicator/indicated-turn-rate");
    simVals.push_back("/instrumentation/vertical-speed-indicator/indicated-speed-fpm");
    simVals.push_back("/controls/flight/aileron");
    simVals.push_back("/controls/flight/elevator");
    simVals.push_back("/controls/flight/rudder");
    simVals.push_back("/controls/flight/flaps");
    simVals.push_back("/controls/engines/engine/throttle");
    simVals.push_back("/engines/engine/rpm");
}

int read(int socketid, string& out, int bytes) {
    out.resize(bytes);
    read(socketid, &out[0], bytes);
}

#endif //PROJECT1_OPENDATASERVERCOMMAND_H

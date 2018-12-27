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
#include <mutex>
#include <string>
#include <thread>
#include <sys/socket.h>
#include <strings.h>
#include "Command.h"
#include "SymbolTable.h"
class openDataServerCommand:public Command{
private:
    SymbolTable* vars;
    vector<string> simValues;
    Calculator* calc;
    bool acceptServer = false;
    int socket_id;
public:
    openDataServerCommand(SymbolTable* &v);

    void serverOpen(int port ,int Hz);
    string installValuesFromSim(string line);

    int doCommand(vector<vector<string>> strings);
    void installfirstVals(vector<string> &simVals);

    virtual ~openDataServerCommand();

};



#endif //PROJECT1_OPENDATASERVERCOMMAND_H

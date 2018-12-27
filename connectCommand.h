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
#include <mutex>
#include <map>
#include <thread>
#include "Expression.h"
#include "Command.h"
#include "SymbolTable.h"

class connectCommand:public Command{
private:
    SymbolTable* vars;
    map<string,string >* bindingMap;
    Calculator* calc;
    int socket_id;
    bool * stillRun;
public:
    connectCommand(SymbolTable* v, map<string, string>* bi,bool * run);

    int doCommand(vector<vector<string>> strings) override;

    void serverConnct(int port ,string ip);

    virtual ~connectCommand();
};
#endif //PROJECT1_CONECTCOMMAND_H

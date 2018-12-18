//
// Created by ori on 12/17/18.
//
#ifndef PROJECT1_OPENDATASERVERCOMMAND_H
#define PROJECT1_OPENDATASERVERCOMMAND_H

#include <map>
#include "Expression.h"
#include "Command.h"
class openDataServerCommand:public Command{
private:
    map<string,double > vars;
public:
    openDataServerCommand(map<string, double> &v){
        vars =v;
    }

    int doCommand(list<string> param) override {

    }
};
#endif //PROJECT1_OPENDATASERVERCOMMAND_H

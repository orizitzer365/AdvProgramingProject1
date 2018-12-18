//
// Created by ori on 12/17/18.
//

#ifndef PROJECT1_DEFINEVARCOMMAND_H
#define PROJECT1_DEFINEVARCOMMAND_H
#include <map>
#include "Expression.h"
#include "Command.h"
class defineVarCommand:public Command{
private:
    map<string,double > vars;
public:
    defineVarCommand(map<string, double> &v){
        vars =v;
    }

    int doCommand(list<string> param) override {

    }
};

#endif //PROJECT1_DEFINEVARCOMMAND_H

//
// Created by ori on 12/18/18.
//

#ifndef PROJECT1_PRINTCOMMAND_H
#define PROJECT1_PRINTCOMMAND_H

#include <map>
#include <iostream>
#include "Command.h"
#include "Var.h"

class printCommand : public Command{
private:
    SymbolTable vars;
public:
    printCommand(SymbolTable &vars) : vars(vars) {}

    int doCommand(vector<vector<string>> strings) override {
        vector<string> param = strings.at(0);
        if(param.size()!= 2)
            throw "invalid parmameters";
        if(param.at(1)[0]=='"')
            cout<<param.at(1).substr(1,param.at(1).size()-1);
        else
            cout<<vars.at(param.at(1))->calculate({});
        return 1;
    }
};
#endif //PROJECT1_PRINTCOMMAND_H

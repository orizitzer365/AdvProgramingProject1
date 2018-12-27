//
// Created by ori on 12/18/18.
//

#ifndef PROJECT1_PRINTCOMMAND_H
#define PROJECT1_PRINTCOMMAND_H

#include <map>
#include <iostream>
#include "Command.h"

class printCommand : public Command{
private:
    SymbolTable* vars;
public:
    printCommand(SymbolTable* &va) : vars(va) {}

    int doCommand(vector<vector<string>> strings) override {
        vector<string> param = strings.at(0);
        if(param.size()!= 2)
            throw "invalid parmameters";
        //print the string from the input
        if(param.at(1)[0]=='"')
            cout<<param.at(1).substr(1,param.at(1).size()-2)<<endl;
        else
            //print the value of the expression:
            cout<< Calculator(vars).calculate(param.at(1))<<endl;
        return 1;
    }
};
#endif //PROJECT1_PRINTCOMMAND_H
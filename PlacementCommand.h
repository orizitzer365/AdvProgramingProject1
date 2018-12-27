//
// Created by ori on 12/19/18.
//

#ifndef PROJECT1_PLACEMENTCOMMAND_H
#define PROJECT1_PLACEMENTCOMMAND_H

#include "Command.h"
#include "Expression.h"

class PlacementCommand:public Command{
private:
    SymbolTable* vars;
    Calculator* calc;
public:
    PlacementCommand(SymbolTable* &v) : vars(v) {
        calc = new Calculator(vars);
    }

    int doCommand(vector<vector<string>> strings) override {
        vector<string> param = strings.at(0);
        string varName = param.at(0);
        if(param.at(1)=="}")
            return 1;
        if(param.at(1)!="=")
            throw "ERROR";
        //change the value
        vars->at(varName)->setValue(calc->calculate(param.at(2)));
        return 1;
    }
    ~PlacementCommand(){
        delete calc;
    }
};
#endif //PROJECT1_PLACEMENTCOMMAND_H

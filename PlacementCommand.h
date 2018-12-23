//
// Created by ori on 12/19/18.
//

#ifndef PROJECT1_PLACEMENTCOMMAND_H
#define PROJECT1_PLACEMENTCOMMAND_H

#include "Command.h"
#include "Expression.h"
#include "Var.h"

class PlacementCommand:public Command{
private:
    map<string,string > bindingMap;
    SymbolTable vars;
    Calculator calc;
public:
    PlacementCommand(SymbolTable &v, map<string, string> &b, Calculator &c) : vars(v) , bindingMap(b)
    ,calc(c){}

    int doCommand(vector<vector<string>> strings) override {
        vector<string> param = strings.at(0);
        string varName = param.at(0);
        if(param.at(2) != "bind"){
            //=
            vars.add(make_pair(varName,calc.calculate(param.at(2)));
            return 1;
        }
        bindingMap.insert(make_pair(varName,param.at(3)));
        vars.bind(varName,param.at(3));
        return 1;
    }
};
#endif //PROJECT1_PLACEMENTCOMMAND_H

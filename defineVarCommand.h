//
// Created by ori on 12/17/18.
//

#ifndef PROJECT1_DEFINEVARCOMMAND_H
#define PROJECT1_DEFINEVARCOMMAND_H
#include <map>
#include "Expression.h"
#include "Command.h"
#include "PlacementCommand.h"
#include "SymbolTable.h"

class defineVarCommand:public Command{
private:
    SymbolTable vars;
    map<string,string > bindingMap;
    Calculator calc;
public:
    defineVarCommand(SymbolTable &v, map<string, string> &b, Calculator &c):calc(c) {
        vars =v;
        bindingMap=b;
        calc=c;
    }

    int doCommand(vector<vector<string>> strings) override {
        vector<string> param = strings.at(0);
        string varName = param.at(1);
        vars.add(varName,0);
        if(param.at(2)!="=")
            return 1;
        PlacementCommand placementCommand(vars, bindingMap, calc);
        vector<vector<string>> clone = strings;
        clone.at(0).erase(clone.at(0).begin());
        placementCommand.doCommand(clone);
        return 1;

    }
};

#endif //PROJECT1_DEFINEVARCOMMAND_H

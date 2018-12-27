//
// Created by ori on 12/17/18.
//

#ifndef PROJECT1_DEFINEVARCOMMAND_H
#define PROJECT1_DEFINEVARCOMMAND_H
#include <map>
#include <mutex>
#include "Expression.h"
#include "Command.h"
#include "PlacementCommand.h"
#include "SymbolTable.h"

class defineVarCommand:public Command{
private:
    SymbolTable *vars;
    map<string,string >* bindingMap;
    Calculator* calc;
public:
    defineVarCommand(SymbolTable* &v, map<string, string>* &b) {
        vars =v;
        bindingMap=b;
        calc=new Calculator(vars);
    }

    int doCommand(vector<vector<string>> strings) override {
        mutex mtx;
        mtx.lock();
        vector<string> param = strings.at(0);
        string varName = param.at(1);
        //if it only deifne of var
        if(param.size()==2){
            vars->add(varName,0);
            return 1;
        }
        //if it not binding var
        if(param.at(3) != "bind"){
            vars->add((varName),(calc->calculate(param.at(3))));
            return 1;
        }
        //if it simulator var add it into binding map
        if(param.at(4).at(0)=='"')
            bindingMap->insert(make_pair(varName,param.at(4).substr(1,param.at(4).size()-2)));
        //bind the var's
        vars->bind(varName,param.at(4));
        mtx.unlock();
        return 1;
    }
};

#endif //PROJECT1_DEFINEVARCOMMAND_H

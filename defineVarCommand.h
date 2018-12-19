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
    map<string,string > bindingMap;
public:
    defineVarCommand(map<string, double> &v,map<string,string > &b){
        vars =v;
        bindingMap=b;
    }

    int doCommand(vector<string> param) override {
        string varName = param.at(1);
        if(param.at(2)!="=")
            return 3;
        if(param.at(3) != "bind"){
            //=
            vars.insert(make_pair(varName,new Expression(param.at(3))));
            return 4;
        }
        bindingMap.insert(make_pair(varName,param.at(3)));
        if(param.at(3)[0]!='"')
            vars.insert(make_pair(varName,vars.find(param.at(3))->second));
        return 4;
    }
};

#endif //PROJECT1_DEFINEVARCOMMAND_H

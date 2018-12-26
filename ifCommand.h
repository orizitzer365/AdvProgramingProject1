//
// Created by ori on 12/18/18.
//

#ifndef PROJECT1_IFCOMMAND_H
#define PROJECT1_IFCOMMAND_H
#include "ConditionParser.h"
class ifCommand:public ConditionParser{
public:
    ifCommand(map<string, Expression *>* &co,SymbolTable * & s) : ConditionParser(co, s) {}

    int doCommand(vector<vector<string>> param){
        int x=0;
        int r=0;
        //install the condition and the commands
        ConditionParser::doCommand(param);
        if (ConditionParser::getConditionStatus()){
            r=0;
            vector<vector<string>> clone = param;
            clone.erase(clone.begin());
            //execute the commands
            for(auto& i :ConditionParser::getCommands()){
                x= i->calculate(clone);
                r+=x;
                clone.erase(clone.begin(),clone.begin()+x);
            }
        }
        return r;
    }
};
#endif //PROJECT1_IFCOMMAND_H

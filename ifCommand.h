//
// Created by ori on 12/18/18.
//

#ifndef PROJECT1_IFCOMMAND_H
#define PROJECT1_IFCOMMAND_H
#include "ConditionParser.h"
class ifCommand:public ConditionParser{
public:
    ifCommand(map<string, Expression *> &co, Calculator &c) : ConditionParser(co, c) {}

    int doCommand(vector<vector<string>> param){
        vector<vector<string>> clone = param;
        int x=0;
        if(ConditionParser::getConditionStatus()){
            for(auto& i :ConditionParser::getCommands()){
                x+=i->calculate(clone);
                clone.erase(clone.begin());
            }
        }
        return x;
    }
};
#endif //PROJECT1_IFCOMMAND_H

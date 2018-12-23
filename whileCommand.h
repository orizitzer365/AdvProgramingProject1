//
// Created by ori on 12/18/18.
//

#ifndef PROJECT1_WHILECOMMAND_H
#define PROJECT1_WHILECOMMAND_H

#include "ConditionParser.h"
class whileCommand:public ConditionParser{
public:
    whileCommand(map<string, Expression *> &co,Calculator &c) : ConditionParser(co, c) {}

    int doCommand(vector<vector<string>> param){
        int x=0;
        while (ConditionParser::getConditionStatus()){
            x=0;
            vector<vector<string>> clone = param;
            for(auto& i :ConditionParser::getCommands()){
                x+=i->calculate(clone);
                clone.erase(clone.begin());
            }
        }
        return x;
    }
};
#endif //PROJECT1_WHILECOMMAND_H

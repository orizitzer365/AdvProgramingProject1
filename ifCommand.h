//
// Created by ori on 12/18/18.
//

#ifndef PROJECT1_IFCOMMAND_H
#define PROJECT1_IFCOMMAND_H
#include "ConditionParser.h"
class ifCommand:public ConditionParser{
public:
    ifCommand(map<string,Command*> &co):ConditionParser(co){}

    int doCommand(vector<string> param){
        int x=0;
        if(ConditionParser::getConditionStatus()){
            x=0;
            for(const auto& i :ConditionParser::getCommands())
                x+=i.doCommand();
        }
        return x;
    }
};
#endif //PROJECT1_IFCOMMAND_H

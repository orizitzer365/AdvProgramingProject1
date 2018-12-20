//
// Created by ori on 12/18/18.
//

#ifndef PROJECT1_WHILECOMMAND_H
#define PROJECT1_WHILECOMMAND_H

#include "ConditionParser.h"
class whileCommand:public ConditionParser{
public:
    whileCommand(map<string,Command*> &co):ConditionParser(co){}

    int doCommand(vector<string> param){
        int x=0;

        while(getConditionStatus()){
            x=0;
            for(auto& i : getCommands())
                x+= i.doCommand(param);
        }
        return x;
    }
};
#endif //PROJECT1_WHILECOMMAND_H

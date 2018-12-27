//
// Created by ori on 12/18/18.
//

#ifndef PROJECT1_WHILECOMMAND_H
#define PROJECT1_WHILECOMMAND_H

#include "ConditionParser.h"
class whileCommand:public ConditionParser{
public:
    whileCommand(map<string, Expression *>* &co, SymbolTable* & v) : ConditionParser(co, v) {}

    int doCommand(vector<vector<string>> param){
        int x=0;
        int r=0;
        //install the commands and the condition
        ConditionParser::doCommand(param);
        //do it while the condtion is true
        while (ConditionParser::getConditionStatus()){
            x=0;
            r=0;
            //clone the lines
            vector<vector<string>> clone = param;
            clone.erase(clone.begin());
            for(auto& i :ConditionParser::getCommands()){
                //execute the command
                x= i->calculate(clone);
                r+=x;
                clone.erase(clone.begin(),clone.begin()+x);
            }
        }
        //one for while and one for "}"
        return r+2;
    }

    ~whileCommand() {}
};
#endif //PROJECT1_WHILECOMMAND_H

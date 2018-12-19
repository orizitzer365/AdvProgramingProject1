//
// Created by ori on 12/18/18.
//

#ifndef PROJECT1_CONDITIONPARSER_H
#define PROJECT1_CONDITIONPARSER_H

#include <map>
#include "Command.h"
#include "Expression.h"

class ConditionParser:public Command{
private:
    list<Command> commands;
    map<string,Command> commmandsMap;
    Expression condition;
public:
    ConditionParser(map<string,Command> &co):commmandsMap(co) {
    }

    virtual int doCommand(vector<string> param)  {
        condition = new booleanExpression(param);
        int i=1;
        while(param.at(i)!="{")
            i++;
        i++;
        commands
    }

    bool &getConditionStatus() const {
        return (condition.caculate()==1)?1:0;
    }

    const list<Command> &getCommands() const {
        return commands;
    }
};
#endif //PROJECT1_CONDITIONPARSER_H

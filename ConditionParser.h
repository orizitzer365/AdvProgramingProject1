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
    vector<Expression*> commands;
    map<string,Expression* > commandsMap;
    string condition;
    Calculator calc;
public:
    ConditionParser(map<string, Expression *> &co, Calculator &c) : commandsMap(co),calc(c) {
    }

    virtual int doCommand(vector<vector<string>> param)  {
        vector<vector<string>> clone = param;
        clone.at(0).erase(clone.at(0).begin());
        condition = (param.at(0).at(1));
        clone.erase(clone.begin());
        getCommandsByMap(clone);
        return 1;
//        commands
    }

    bool getConditionStatus() {
        return (calc.calculate(condition) ==1) ? 1 : 0;
    }

    void getCommandsByMap(vector<vector<string > > lines) {
        int i = 0;
        ///change to while '}'
        for (auto& line : lines) {
            if(line.at(0)=="}")
                break;
            if(commandsMap.find(line.at(0)) == commandsMap.end())
                commands.at(i) = commandsMap.at("placement");
            else
                commands.at(i) = commandsMap.at(line.at(0));
        }
    }

    vector<Expression *> &getCommands() {
        return commands;
    }
};
#endif //PROJECT1_CONDITIONPARSER_H

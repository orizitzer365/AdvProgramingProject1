//
// Created by ori on 12/21/18.
//

#ifndef PROJECT1_COMMANDEXPERSSION_H
#define PROJECT1_COMMANDEXPERSSION_H

#include "Expression.h"
#include "Command.h"

class CommandExpression : public Expression{
private:
    Command* command;
public:
    CommandExpression(Command *command) : command(command) {}

    double calculate(vector<vector<string>> strings)  {
        return command->doCommand(strings);
    }
};
#endif //PROJECT1_COMMANDEXPERSSION_H

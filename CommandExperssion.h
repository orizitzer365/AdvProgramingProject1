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
    CommandExpression(Expression* x,Expression* y):Expression(x,y){
        command= nullptr;
    }
    CommandExpression(Command *command) : Expression(nullptr, nullptr) ,command(command) {}

    double calculate(vector<vector<string>>& strings)  {
        return command->doCommand(strings);
    }

    double func(double x, double y) override {
        return 0;
    }
    virtual ~CommandExpression();
};
#endif //PROJECT1_COMMANDEXPERSSION_H

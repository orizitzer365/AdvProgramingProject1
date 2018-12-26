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
    map<string,Expression* >* commandsMap;
    string condition;
    Calculator* calc;
public:
    ConditionParser(map<string, Expression *>* co,SymbolTable* vars);

    virtual int doCommand(vector<vector<string>> param);

    bool getConditionStatus();

    void getCommandsByMap(vector<vector<string > > lines);
    vector<Expression *> &getCommands();
};
#endif //PROJECT1_CONDITIONPARSER_H

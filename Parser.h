//
// Created by ori on 12/17/18.
//

#ifndef PROJECT1_PARSER_H
#define PROJECT1_PARSER_H
#include <string>
#include <list>
#include <map>
#include "Command.h"
using namespace std;

#include "PrintCommand.h"
#include "openDataServerCommand.h"
#include "conectCommand.h"
#include "PlacementCommand.h"
#include "ifCommand.h"
#include "whileCommand.h"
#include "SleepCommand.h"
#include "CommandExperssion.h"

class Parser {
private:
    map<string , Expression*> commands;
    map<string,string > bindingMap;
public:
    Parser(SymbolTable &vars){
        Calculator c(vars);
        commands.insert(make_pair("print",new CommandExpression(new printCommand(vars))));
        commands.insert(make_pair("openDataServer", new CommandExpression(
                new openDataServerCommand(vars, c))));
        commands.insert(make_pair("connect",new CommandExpression(new conectCommand(vars, bindingMap, c))));
        commands.insert(make_pair("placement",new CommandExpression(
                new PlacementCommand(vars, bindingMap, c))));
        commands.insert(make_pair("if",new CommandExpression(new ifCommand(commands, c))));
        commands.insert(make_pair("while",new CommandExpression(new whileCommand(commands, c))));
        commands.insert(make_pair("sleep",new CommandExpression(new SleepCommand(vars))));
    }
    void parse(vector<vector<string > > strings);
};


#endif //PROJECT1_PARSER_H

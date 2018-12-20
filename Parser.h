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

class Parser {
private:
    map<string , Command*> commands;
    map<string,string > bindingMap;
public:
    Parser(map <string,double > vars){
        commands.insert(make_pair("print",new printCommand(vars)));
        commands.insert(make_pair("openDataServer",new openDataServerCommand(vars,bindingMap)));
        commands.insert(make_pair("connect",new conectCommand(vars,bindingMap)));
        //commands.insert(make_pair("print",new PlacementCommand(vars)));
        commands.insert(make_pair("if",new ifCommand(commands)));
        commands.insert(make_pair("while",new whileCommand(commands)));
    }
    void parse(vector<string> strings);
};


#endif //PROJECT1_PARSER_H

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
#include "connectCommand.h"
#include "PlacementCommand.h"
#include "ifCommand.h"
#include "whileCommand.h"
#include "SleepCommand.h"
#include "CommandExperssion.h"

class Parser {
private:
    map<string , Expression*>* commands;
    map<string,string >* bindingMap;
    bool* stillRunning;
public:
    Parser(SymbolTable* &vars);
    void parse(vector<vector<string > > strings);

    virtual ~Parser();
};


#endif //PROJECT1_PARSER_H

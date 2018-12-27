//
// Created by ori on 12/17/18.
//

#include "Parser.h"
#include "defineVarCommand.h"
#include "Enterc.h"

void Parser::parse(vector<vector<string > > strings) {
    Expression* command;
    while(strings.size()>0){
        //check what command there is in the first string of the kine
        if(commands->find(strings.at(0).at(0)) == commands->end())
            command = commands->at("placement");
        else
            command = commands->at(strings.at(0).at(0));
        //execute the command
        int i = command->calculate(strings);
        //earase the line from the lines
        strings.erase(strings.begin(),strings.begin()+i);
    }
}

Parser::Parser(SymbolTable* &vars) {
    //install the commands map
    commands = new map<string,Expression* >();
    bindingMap = new map<string,string >();
    commands->insert(make_pair("print",new CommandExpression(new printCommand(vars))));
    commands->insert(make_pair("openDataServer", new CommandExpression(
            new openDataServerCommand(vars))));
    commands->insert(make_pair("connect",new CommandExpression(new connectCommand(vars, bindingMap))));
    commands->insert(make_pair("placement",new CommandExpression(
            new PlacementCommand(vars))));
    commands->insert(make_pair("var",new CommandExpression(new defineVarCommand(vars,bindingMap))));
    commands->insert(make_pair("if",new CommandExpression(new ifCommand(commands, vars))));
    commands->insert(make_pair("while",new CommandExpression(new whileCommand(commands, vars))));
    commands->insert(make_pair("sleep",new CommandExpression(new SleepCommand(vars))));
    commands->insert(make_pair("Enterc",new CommandExpression(new Enterc())));
}

Parser::~Parser() {
    for(map<string,Expression* >::iterator it = commands->begin();it!=commands->end();++it)
        delete it->second;
    delete commands;
    delete( bindingMap);
}

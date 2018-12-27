//
// Created by ori on 12/26/18.
//
#include "ConditionParser.h"
ConditionParser::ConditionParser(map<string, Expression *> *co, SymbolTable *vars) : commandsMap(co) {
    calc = new Calculator(vars);
}

int ConditionParser::doCommand(vector <vector<string>> param) {
    //clone the lines
    vector<vector<string>> clone = param;
    //get the condition
    condition = (param.at(0).at(1));
    clone.erase(clone.begin());
    //get the commands
    getCommandsByMap(clone);
    return 1;
//        commands
}

bool ConditionParser::getConditionStatus() {
    return (calc->calculate(condition) ==1) ? 1 : 0;
}

void ConditionParser::getCommandsByMap(vector <vector<string>> lines) {
    int i = 0;
    //get the command that need to do in each line
    for (auto& line : lines) {
        if(line.at(0)=="}")
            break;
        if(commandsMap->find(line.at(0)) == commandsMap->end())
            commands.push_back( commandsMap->at("placement"));
        else
            commands.push_back(commandsMap->at(line.at(0)));
        i++;
    }

}

vector<Expression *> &ConditionParser::getCommands() {
    return commands;
}

ConditionParser::~ConditionParser() {

}

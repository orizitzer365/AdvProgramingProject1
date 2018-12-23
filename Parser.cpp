//
// Created by ori on 12/17/18.
//

#include "Parser.h"

void Parser::parse(vector<vector<string > > strings) {
    Expression* command;
    while(strings.size()>0){
        if(commands.find(strings.at(0).at(0)) == commands.end())
            command = commands.at("placement");
        else
            command = commands.at(strings.at(0).at(0));
        int i = command->calculate(strings);
        strings.erase(strings.begin(),strings.begin()+i);
    }
}

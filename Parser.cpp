//
// Created by ori on 12/17/18.
//

#include "Parser.h"

void Parser::parse(vector<string> strings) {
    while(strings.size()>0){
        int i = commands.at(strings.at(0))->doCommand(strings);
        strings.erase(strings.begin(),strings.begin()+i);
    }
}

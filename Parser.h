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


class Parser {
private:
    map<string , Command> commands;
public:
    void parse(list<string> strings);
};


#endif //PROJECT1_PARSER_H

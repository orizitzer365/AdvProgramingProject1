//
// Created by ori on 12/17/18.
//

#ifndef PROJECT1_COMMAND_H
#define PROJECT1_COMMAND_H

#include <string>
#include <list>
#include <vector>
#include <map>
using namespace std;
class Command{
public:
    virtual int doCommand(vector<string> param) = 0;
};
#endif //PROJECT1_COMMAND_H

//
// Created by ori on 12/18/18.
//

#ifndef PROJECT1_PRINTCOMMAND_H
#define PROJECT1_PRINTCOMMAND_H

#include <map>
#include <iostream>
#include "Command.h"
class printCommand : public Command{
public:
    int doCommand(vector<string> param) override {
        cout<<param.at(1);
        return 2;
    }
};
#endif //PROJECT1_PRINTCOMMAND_H

//
// Created by ori on 12/20/18.
//

#ifndef PROJECT1_SLEEPCOMMAND_H
#define PROJECT1_SLEEPCOMMAND_H

#include <unistd.h>
#include "Command.h"
#include "Var.h"

class  SleepCommand : public Command{
private:
   SymbolTable vars;
public:
    SleepCommand(SymbolTable &vars) : vars(vars) {}

    int doCommand(vector< vector< string > > strings) override {
        if(strings.at(0).size()!=3)
            throw "invalid parmameters";
        vector<string> param = strings.at(0);
        sleep(stod(param.at(0)));
        return 1;
    }
};
#endif //PROJECT1_SLEEPCOMMAND_H

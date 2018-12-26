//
// Created by ori on 12/20/18.
//

#ifndef PROJECT1_SLEEPCOMMAND_H
#define PROJECT1_SLEEPCOMMAND_H

#include <unistd.h>
#include "Command.h"

class  SleepCommand : public Command{
private:
   SymbolTable* vars;
public:
    SleepCommand(SymbolTable* &vars) : vars(vars) {}

    int doCommand(vector< vector< string > > strings) override {
        if(strings.at(0).size()!=2)
            throw "invalid parmameters";
        vector<string> param = strings.at(0);
        //sleep for the number of miliseconds from the input
        sleep(stoi(param.at(1))/1000);
        return 1;
    }
};
#endif //PROJECT1_SLEEPCOMMAND_H

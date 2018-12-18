//
// Created by ori on 12/18/18.
//

#ifndef PROJECT1_PRINTCOMMAND_H
#define PROJECT1_PRINTCOMMAND_H

#include <map>
#include "Command.h"
class printCommand : public Command{
private:
    map<string,double > vars;
public:
    printCommand(map<string,double >& v){
        vars = v;
    }
    int doCommand(list<string> param) override {
        printf("print");
    }
};
#endif //PROJECT1_PRINTCOMMAND_H

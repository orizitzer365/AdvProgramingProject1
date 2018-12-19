//
// Created by ori on 12/19/18.
//

#ifndef PROJECT1_PLACEMENTCOMMAND_H
#define PROJECT1_PLACEMENTCOMMAND_H

#include "Command.h"
#include "Expression.h"

class PlacementCommand:public Command{
private:
    map<string , double > vars;
public:
    PlacementCommand(const map<string, double> &vars) : vars(vars) {}

    int doCommand(vector<string> param) override {

        BinaryExpression val(param.at(3));
        double newVal = val.caculate();
        vars.at(param.at(0))=newVal;

    }
};
#endif //PROJECT1_PLACEMENTCOMMAND_H

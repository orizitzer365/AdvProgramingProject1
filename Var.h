//
// Created by ori on 12/20/18.
//

#ifndef PROJECT1_VAR_H
#define PROJECT1_VAR_H

#include "Expression.h"

class Var: public Expression{
private:
    double value;
public:
    Var(double value) : value(value) {}

    double calculate(vector<vector<string>> list1) override {
        return value;
    }

    void setValue(double value) {
        Var::value = value;
    }
};
#endif //PROJECT1_VAR_H

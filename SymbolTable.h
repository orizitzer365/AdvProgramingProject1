//
// Created by ori on 12/22/18.
//

#ifndef PROJECT1_SYMBOLTABLE_H
#define PROJECT1_SYMBOLTABLE_H
using namespace std;
#include "map"
#include "Var.h"


class SymbolTable{
private:
    map<string , Var* > vars;

public:
    SymbolTable() {}

    void add(string name, double val){
        vars.insert(make_pair(name, new Var(val)));
    }
    void add(string name, Var* &val){
        vars.insert(make_pair(name, val));
    }
    void bind(string newArg , string bining){
        if(bining[0]!='"')
            vars.insert(make_pair(newArg,vars.at(bining.substr(1,bining.size()-1))));
        else
            vars.insert(make_pair(newArg,vars.at(bining)));
    }
    Var* &at(string name){
        return vars.at(name);
    }
    bool exists(string var){
        return vars.find(var)!=vars.end();
    }
};
#endif //PROJECT1_SYMBOLTABLE_H

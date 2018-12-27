//
// Created by ori on 12/22/18.
//

#ifndef PROJECT1_SYMBOLTABLE_H
#define PROJECT1_SYMBOLTABLE_H
using namespace std;

#include "Expression.h"
#include <functional>
#include "map"
//A class that contain map of vars and manage it

class SymbolTable{
private:
    map<string , Var* > vars;
public:
    SymbolTable() {}
    //add the var
    void add(string name, double val){
        vars.insert(make_pair(name, new Var(val)));
    }
    void add(string name, Var* &val){
        vars.insert(make_pair(name, val));
    }
    //binding between the vars
    void bind(string newArg , string binding){
        add(newArg,0);
        if(binding[0]=='"'){
            if(exists(binding.substr(1,binding.size()-2))) {
                Var* temp = vars.at(newArg);
                //delete(vars.at(newArg));
                vars.at(newArg) = vars.at(binding.substr(1, binding.size() - 2));
                delete temp;
            }
            else{
                bind(binding.substr(1,binding.size()-2),newArg);
                return;
            }
        }
        else{
            Var* temp = vars.at(newArg);
            //delete(vars.at(newArg));
            vars.at(newArg)=ref(vars.at(binding));
            delete(temp);
        }

    }
    //get the var with the name
    Var* &at(string name){
        return vars.at(name);
    }
    //return true if the map contain the var
    bool exists(string var){
        return vars.find(var)!=vars.end();
    }
    int size(){
        return vars.size();
    };
    ~SymbolTable(){
        for(auto it:vars){
            try {
                delete it.second;
            }catch (exception &e){}
        }
        vars.clear();
    }
};
#endif //PROJECT1_SYMBOLTABLE_H

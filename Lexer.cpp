//
// Created by ori on 12/17/18.
//

#include <iostream>
#include <fstream>
#include "Lexer.h"

list<string> Lexer::lexer(string fileName) {
    list<string> list;
    ifstream stream(fileName);
    string temp = "";
    if(stream.fail())
        return list;
    while(!stream.eof()){
        stream >> temp;
        list.push_back(temp);
    }
    return list;
}

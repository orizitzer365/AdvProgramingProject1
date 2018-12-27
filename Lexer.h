//
// Created by ori on 12/17/18.
//

#ifndef PROJECT1_LEXER_H
#define PROJECT1_LEXER_H


#include <string>
#include <list>
#include <vector>
#include <set>

using namespace std;

class Lexer {
    set<string> makeSet();
    bool add(string& last,string& word);
public:
    vector<vector<string>> lexer(string fileName);
};


#endif //PROJECT1_LEXER_H

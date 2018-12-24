//
// Created by nadav on 12/24/18.
//

#ifndef PROJECT1_LEXSER_H
#define PROJECT1_LEXSER_H

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


#endif //PROJECT1_LEXSER_H

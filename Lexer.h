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

/**
 * class of lexer.
 */
class Lexer {
    /**
     * set of the valid commands that has params.
     */
    set<string> makeSet();
    /**
     * check and adds two parts of expressions.
     */
    bool add(string& last,string& word);
public:
    /**
     * lexing the file.
     */
    vector<vector<string>> lexer(string fileName);
};


#endif //PROJECT1_LEXSER_H

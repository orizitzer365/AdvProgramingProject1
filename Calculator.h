//created by Nadav Panski
#ifndef PROJECT1_CALCULATOR_H
#define PROJECT1_CALCULATOR_H

using namespace std;
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include "ExpressionFactory.h"
#include "SymbolTable.h"
enum DetailType {ACTION,VARIABLE,NUMBER,PARENTHESIS};

/**
 * class that calculates expressions.
 */
class Calculator {

    //members:
    SymbolTable* variables;
    ExpressionFromNameFactory factory;
    map<unsigned int,double> parenthesis;
    int lastParenthesis;
    map<string,int> precedence;

    //private functions:
    /**
     * separates the string to parts.
     */
     queue<pair<DetailType,string>>expressionLexerAndParser(string& input);
     /**
      * Arranges the parts to prefix.
      */
     stack<pair<DetailType,string>>prefix(queue<pair<DetailType,string>>& input);
     /**
      * creates the expression.
      */
     Expression* getExpression(stack<pair<DetailType,string>>& que);
     /**
      * saves parenthesis expressions.
      */
     pair<DetailType ,string> addParenthesis(string input);
public:
    /**
     * constructor.
     */
     Calculator(SymbolTable* s);
    /**
     * calculates the value of string.
     */
     double calculate(string input);
};


#endif //PROJECT1_CALCULATOR_H

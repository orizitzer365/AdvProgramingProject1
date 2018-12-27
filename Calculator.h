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


class Calculator {

    SymbolTable* variables;
    ExpressionFromNameFactory factory;
    map<unsigned int,double> parenthesis;
    int lastParenthesis;
    map<string,int> precedence;

     queue<pair<DetailType,string>>expressionLexerAndParser(string& input);
     stack<pair<DetailType,string>>prefix(queue<pair<DetailType,string>>& input);
     Expression* getExpression(stack<pair<DetailType,string>>& que);
     pair<DetailType ,string> addParenthesis(string input);
public:
    Calculator(SymbolTable* s);
    double calculate(string input);
};


#endif //PROJECT1_CALCULATOR_H

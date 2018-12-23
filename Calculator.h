#ifndef PROJECT1_CALCULATOR_H
#define PROJECT1_CALCULATOR_H

using namespace std;
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include "ExpressionFactory.h"
class SymbolTable;////////////////////////////////////////////////////////

enum DetailType {ACTION,VARIABLE};

class Calculator {
    SymbolTable* variables;
    ExpressionFromNameFactory factory;

     queue<pair<DetailType,string>>expressionLexerAndParser();
public:
    Calculator(SymbolTable* s);
    double calculate(string input);
};


#endif //PROJECT1_CALCULATOR_H

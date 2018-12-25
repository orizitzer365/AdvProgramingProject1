//
// Created by nadav on 12/23/18.
//

#ifndef PROJECT1_EXPRESSION_H
#define PROJECT1_EXPRESSION_H

#include <vector>
#include <string>
using namespace std;

class Expression {
protected:
    Expression* e1;
    Expression* e2;
public:
    Expression(Expression* e1,Expression* e2);
    virtual double calculate();
    virtual double calculate(vector<vector<string>> notUsed);
    virtual double func(double x, double y) = 0;
    ~Expression();
};

class Plus : public  Expression{
public:
    Plus(Expression* e1,Expression* e2);
    double calculate();
    double func(double x, double y);
};

class Minus : public  Expression{
public:
    Minus(Expression* e1,Expression* e2);
    double calculate();
    double func(double x, double y);
};

class Mult : public  Expression{
public:
    Mult(Expression* e1,Expression* e2);
    double calculate();
    double func(double x, double y);
};

class Div : public  Expression{
public:
    Div(Expression* e1,Expression* e2);
    double calculate();
    double func(double x, double y);
};

class IsEqual : public  Expression{
public:
    IsEqual(Expression* e1,Expression* e2);
    double calculate();
    double func(double x, double y);
};

class IsNotEqual : public  Expression{
public:
    IsNotEqual(Expression* e1,Expression* e2);
    double calculate();
    double func(double x, double y);
};

class IsSmaller : public  Expression{
public:
    IsSmaller(Expression* e1,Expression* e2);
    double calculate();
    double func(double x, double y);
};

class IsBigger : public  Expression{
public:
    IsBigger(Expression* e1,Expression* e2);
    double calculate();
    double func(double x, double y);
};

class IsBiggerOrEqual : public  Expression{
public:
    IsBiggerOrEqual(Expression* e1,Expression* e2);
    double calculate();
    double func(double x, double y);
};

class IsSmallerOrEqual : public  Expression{
public:
    IsSmallerOrEqual(Expression* e1,Expression* e2);
    double calculate();
    double func(double x, double y);
};

class Or : public  Expression{
public:
    Or(Expression* e1,Expression* e2);
    double calculate();
    double func(double x, double y);
};

class And : public  Expression{
public:
    And(Expression* e1,Expression* e2);
    double calculate();
    double func(double x, double y);
};

class Var : public Expression{
    double val;
public:
    Var(Expression* value,Expression* not_used);
    Var(double value);
    void setValue(double value);
    double calculate();
    double func(double x, double y);
};

#endif //PROJECT1_EXPRESSION_H

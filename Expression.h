//
// Created by Nadav Panski.
//

#ifndef PROJECT1_EXPRESSION_H
#define PROJECT1_EXPRESSION_H

#include <vector>
#include <string>
using namespace std;

/**
 * class of expression.
 */
class Expression {
protected:
    Expression* e1;
    Expression* e2;
public:
    /**
     * constructor.
     * input: e1 ,e2 expressions.
     */
    Expression(Expression* e1,Expression* e2);
    /**
     * returns the value of the expression.
     */
    virtual double calculate();
    /**
     * returns the value of the expression.
     */
    virtual double calculate(vector<vector<string>>& notUsed);
    /**
     * Doing action between two numbers.
     */
    virtual double func(double x, double y) = 0;

    /**
     * distructor.
     */
    virtual ~Expression();
};

/*
 *
 *
 * All the classes down | are types of expression with the same functions:
 *                      |
 *                      |
 *                      |
 *                     \|/
 *                      |
 *
 */
class Plus : public  Expression{
public:
    ~Plus();
    Plus(Expression* e1,Expression* e2);
    double calculate();
    double func(double x, double y);
};

class Minus : public  Expression{
public:
    ~Minus();
    Minus(Expression* e1,Expression* e2);
    double calculate();
    double func(double x, double y);
};

class Mult : public  Expression{
public:
    ~Mult();
    Mult(Expression* e1,Expression* e2);
    double calculate();
    double func(double x, double y);
};

class Div : public  Expression{
public:
    ~Div();
    Div(Expression* e1,Expression* e2);
    double calculate();
    double func(double x, double y);
};

class IsEqual : public  Expression{
public:
    ~IsEqual();
    IsEqual(Expression* e1,Expression* e2);
    double calculate();
    double func(double x, double y);
};

class IsNotEqual : public  Expression{
public:
    ~IsNotEqual();
    IsNotEqual(Expression* e1,Expression* e2);
    double calculate();
    double func(double x, double y);
};

class IsSmaller : public  Expression{
public:
    ~IsSmaller();
    IsSmaller(Expression* e1,Expression* e2);
    double calculate();
    double func(double x, double y);
};

class IsBigger : public  Expression{
public:
    ~IsBigger();
    IsBigger(Expression* e1,Expression* e2);
    double calculate();
    double func(double x, double y);
};

class IsBiggerOrEqual : public  Expression{
public:
    ~IsBiggerOrEqual();
    IsBiggerOrEqual(Expression* e1,Expression* e2);
    double calculate();
    double func(double x, double y);
};

class IsSmallerOrEqual : public  Expression{
public:
    ~IsSmallerOrEqual();
    IsSmallerOrEqual(Expression* e1,Expression* e2);
    double calculate();
    double func(double x, double y);
};

class Or : public  Expression{
public:
    ~Or();
    Or(Expression* e1,Expression* e2);
    double calculate();
    double func(double x, double y);
};

class And : public  Expression{
public:
    ~And();
    And(Expression* e1,Expression* e2);
    double calculate();
    double func(double x, double y);
};

class Var : public Expression{
    double val;
public:
    ~Var();
    Var(Expression* value,Expression* not_used);
    Var(double value);
    void setValue(double value);
    double calculate();
    double func(double x, double y);
};

#endif //PROJECT1_EXPRESSION_H

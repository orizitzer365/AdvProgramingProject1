//
// Created by nadav on 12/23/18.
//

#include "Expression.h"

#define INVALID_EXP "Invalid expression!"

/*
 *
 * data about the functions at the header file.
 *
 */

Expression::Expression(Expression *e1, Expression *e2) {
    this->e1 = e1;
    this->e2 = e2;
}

double Expression::calculate() {
    if((this->e1 == nullptr)||(this->e2 == nullptr) ){
        throw INVALID_EXP;
    }
    return this->func(this->e1->calculate(),this->e2->calculate());
}

Expression::~Expression() {
    delete this->e1;
    delete this->e2;
}

Plus::Plus(Expression *e1, Expression *e2) : Expression(e1, e2) {}

double Plus::calculate() {
    return Expression::calculate();
}

double Plus::func(double x, double y) {
    return x + y;
}

Minus::Minus(Expression *e1, Expression *e2) : Expression(e1, e2) {}

double Minus::calculate() {
    return Expression::calculate();
}

double Minus::func(double x, double y) {
    return x - y;
}

Mult::Mult(Expression *e1, Expression *e2) : Expression(e1, e2) {}

double Mult::calculate() {
    return Expression::calculate();
}

double Mult::func(double x, double y) {
    return x * y;
}

Div::Div(Expression *e1, Expression *e2) : Expression(e1, e2) {}

double Div::calculate() {
    return Expression::calculate();
}

double Div::func(double x, double y) {
    return x / y;
}

IsEqual::IsEqual(Expression *e1, Expression *e2) : Expression(e1, e2) {}

double IsEqual::calculate() {
    return Expression::calculate();
}

double IsEqual::func(double x, double y) {
    double delta = x - y;
    if((delta > -0.001) && (delta < 0.001)){
        return true;
    }
    return false;
}

IsNotEqual::IsNotEqual(Expression *e1, Expression *e2) : Expression(e1, e2) {}

double IsNotEqual::calculate() {
    return Expression::calculate();
}

double IsNotEqual::func(double x, double y) {
    double delta = x - y;
    if((delta > -0.001) && (delta < 0.001)){
        return false;
    }
    return true;
}

IsSmaller::IsSmaller(Expression *e1, Expression *e2) : Expression(e1, e2) {}

double IsSmaller::calculate() {
    return Expression::calculate();
}

double IsSmaller::func(double x, double y) {
    return x < y;
}

IsBigger::IsBigger(Expression *e1, Expression *e2) : Expression(e1, e2) {}

double IsBigger::calculate() {
    return Expression::calculate();
}

double IsBigger::func(double x, double y) {
    return x > y;
}

IsBiggerOrEqual::IsBiggerOrEqual(Expression *e1, Expression *e2) : Expression(e1, e2) {}

double IsBiggerOrEqual::calculate() {
    return Expression::calculate();
}

double IsBiggerOrEqual::func(double x, double y) {
    return x >= (y - 0.001);
}

IsSmallerOrEqual::IsSmallerOrEqual(Expression *e1, Expression *e2) : Expression(e1, e2) {}

double IsSmallerOrEqual::calculate() {
    return Expression::calculate();
}

double IsSmallerOrEqual::func(double x, double y) {
    return x <= y + 0.001;
}

Or::Or(Expression *e1, Expression *e2) : Expression(e1, e2) {}

double Or::calculate() {
    return Expression::calculate();
}

double Or::func(double x, double y) {
    return x || y;
}

And::And(Expression *e1, Expression *e2) : Expression(e1, e2) {}

double And::calculate() {
    return Expression::calculate();
}

double And::func(double x, double y) {
    return x && y;
}

Var::Var(Expression *value, Expression *not_used) : Expression(value, not_used) {
    this->val = value->calculate();
}

Var::Var(double value) : Expression(nullptr, nullptr) {
    this->val = value;
}

double Var::calculate() {
    return this->val;
}

double Var::func(double x, double y) {
    return this->val;
}

void Var::setValue(double value) {
    this->val = value;
}

double Expression::calculate(vector<vector<string>>& notUsed) {
    return this->calculate();
}

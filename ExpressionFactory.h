#ifndef PROJECT1_EXPRESSIONFACTORY_H
#define PROJECT1_EXPRESSIONFACTORY_H

#include "Expression.h"
#include <map>
#include <string>
using namespace std;

class ExpressionFactory {
public:
    virtual Expression* create(Expression* e1,Expression* e2) = 0;
};

class ExpressionFromNameFactory {
    map<string,ExpressionFactory*> factors;
public:
    ExpressionFromNameFactory();
    virtual Expression* create(string name,Expression* e1,Expression* e2);
    ~ExpressionFromNameFactory();
};

class PlusFactory : public  ExpressionFactory{
public:
    Expression* create(Expression* e1,Expression* e2);
};

class MinusFactory : public  ExpressionFactory{
public:
    Expression* create(Expression* e1,Expression* e2);
};

class  MultFactory : public  ExpressionFactory{
public:
    Expression* create(Expression* e1,Expression* e2);
};

class DivFactory : public  ExpressionFactory{
public:
    Expression* create(Expression* e1,Expression* e2);
};

class IsEqualFactory : public  ExpressionFactory{
public:
    Expression* create(Expression* e1,Expression* e2);
};

class IsNotEqualFactory : public  ExpressionFactory{
public:
    Expression* create(Expression* e1,Expression* e2);
};

class IsSmallerFactory : public  ExpressionFactory{
public:
    Expression* create(Expression* e1,Expression* e2);
};

class IsBiggerFactory : public  ExpressionFactory{
public:
    Expression* create(Expression* e1,Expression* e2);
};

class IsBiggerOrEqualFactory : public  ExpressionFactory{
public:
    Expression* create(Expression* e1,Expression* e2);
};

class IsSmallerOrEqualFactory : public  ExpressionFactory{
public:
    Expression* create(Expression* e1,Expression* e2);
};

class OrFactory : public  ExpressionFactory{
public:
    Expression* create(Expression* e1,Expression* e2);
};

class AndFactory : public  ExpressionFactory{
public:
    Expression* create(Expression* e1,Expression* e2);
};

#endif //PROJECT1_EXPRESSIONFACTORY_H

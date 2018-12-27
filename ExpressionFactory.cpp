#include "ExpressionFactory.h"

#define INVALID_OPTION " is invalid action"

ExpressionFromNameFactory::ExpressionFromNameFactory() {
    this->factors.insert(pair<string,ExpressionFactory*>("+",new PlusFactory()));
    this->factors.insert(pair<string,ExpressionFactory*>("-",new MinusFactory()));
    this->factors.insert(pair<string,ExpressionFactory*>("*",new MultFactory()));
    this->factors.insert(pair<string,ExpressionFactory*>("/",new DivFactory()));
    this->factors.insert(pair<string,ExpressionFactory*>("==",new IsEqualFactory()));
    this->factors.insert(pair<string,ExpressionFactory*>("!=",new IsNotEqualFactory()));
    this->factors.insert(pair<string,ExpressionFactory*>("<",new IsSmallerFactory()));
    this->factors.insert(pair<string,ExpressionFactory*>("<=",new IsSmallerOrEqualFactory()));
    this->factors.insert(pair<string,ExpressionFactory*>(">",new IsBiggerFactory()));
    this->factors.insert(pair<string,ExpressionFactory*>(">=",new IsBiggerOrEqualFactory()));
    this->factors.insert(pair<string,ExpressionFactory*>("||",new OrFactory()));
    this->factors.insert(pair<string,ExpressionFactory*>("&&",new AndFactory()));
}

Expression *ExpressionFromNameFactory::create(string name, Expression *e1, Expression *e2) {
    try{
        return this->factors.at(name)->create(e1,e2);
    } catch(...){
        throw (name + INVALID_OPTION);
    }
}

ExpressionFromNameFactory::~ExpressionFromNameFactory() {
    for(pair<string,ExpressionFactory*> p : this->factors){
        delete p.second;
    }
}

Expression *PlusFactory::create(Expression *e1, Expression *e2) {
    return new Plus(e1,e2);
}

Expression *MinusFactory::create(Expression *e1, Expression *e2) {
    return new Minus(e1,e2);
}

Expression *MultFactory::create(Expression *e1, Expression *e2) {
    return new Mult(e1,e2);
}

Expression *DivFactory::create(Expression *e1, Expression *e2) {
    return new Div(e1,e2);
}

Expression *IsEqualFactory::create(Expression *e1, Expression *e2) {
    return new IsEqual(e1,e2);
}

Expression *IsNotEqualFactory::create(Expression *e1, Expression *e2) {
    return new IsNotEqual(e1,e2);
}

Expression *IsSmallerFactory::create(Expression *e1, Expression *e2) {
    return new IsSmaller(e1,e2);
}

Expression *IsBiggerFactory::create(Expression *e1, Expression *e2) {
    return new IsBigger(e1,e2);
}

Expression *IsBiggerOrEqualFactory::create(Expression *e1, Expression *e2) {
    return new IsBiggerOrEqual(e1,e2);
}

Expression *IsSmallerOrEqualFactory::create(Expression *e1, Expression *e2) {
    return new IsSmallerOrEqual(e1,e2);
}

Expression *OrFactory::create(Expression *e1, Expression *e2) {
    return new Or(e1,e2);
}

Expression *AndFactory::create(Expression *e1, Expression *e2) {
    return new And(e1,e2);
}

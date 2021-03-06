#include "Calculator.h"

#define WHAT "What????"
#define INVALID "Invalid expression"
#define INVALID_EQUAL "Invalid token '=' "

/*
 *
 * all the functions data is in the header file.
 *
 */

double Calculator::calculate(string input) {
    Expression* expression;
    //creates the expression:
    queue<pair<DetailType,string>> inputQueue = this->expressionLexerAndParser(input);
    stack<pair<DetailType,string>> outputStack = this->prefix(inputQueue);
    expression = this->getExpression(outputStack);
    //returns the number:
    double value = expression->calculate();
    delete expression;
    return value;
}

queue<pair<DetailType, string>> Calculator::expressionLexerAndParser(string &input) {
    queue<pair<DetailType, string>> output;
    try{
        // +something === something
        if((input.at(0) == '+' )){
            string newInput;
            bool first = true;
            for(char c : input){
                if(first){
                    first = false;
                    continue;
                }
                newInput = newInput + c;
            }
            output.push(this->addParenthesis(newInput));
            return output;
        }
        // -something = -(something)
        if((input.at(0) == '-' )){
            string newInput = "0" + input;
            output.push(this->addParenthesis(newInput));
            return output;
        }
        int len = input.length();
        //splits the string:
        for(int i=0;i<len;i++){
            char c = input.at(i);
            //number:
            if(c >= '0' && c<='9'){
                string temp;
                //puts the number in temp:
                while(((c >= '0')&&(c <= '9'))||(c == '.')){
                    temp += c;
                    if(i == len - 1){
                        i++;
                        break;
                    }
                    c = input.at(++i);
                }
                --i;
                //adds the number to the output:
                output.push(pair<DetailType,string>(NUMBER,temp));
                continue;
            }
            //variable:
            if((c>='a' && c<='z')||(c>='A' && c<='Z')|| c == '_'){
                string temp;
                //puts the variable in temp:
                while(((c >= '0')&&(c <= '9'))||(c>='a' && c<='z')||(c>='A' && c<='Z')|| c == '_'){
                    temp += c;
                    if(i == len - 1){
                        i++;
                        break;
                    }
                    c = input.at(++i);
                }
                --i;
                //adds the variable to the output:
                output.push(pair<DetailType,string>(VARIABLE,temp));
                continue;
            }
            //double action (operator) with '=':
            if((c=='=')||(c=='<')||(c=='>')){
                if((i < (len -1)) && input.at(i+1) == '='){
                    string temp = string() + c + input.at(i+1);
                    i++;
                    output.push(pair<DetailType,string>(ACTION,temp));
                    continue;
                }
                if(c == '='){
                    throw INVALID_EQUAL;
                }
                string temp = string()+c;
                //adds the action to the output:
                output.push(pair<DetailType,string>(ACTION,temp));
                continue;
            }
            //( ) :
            if(c == '('){
                string temp;
                int count = 1;
                ++i;
                //puts the expression in the () in temp.
                while(i<len){
                    c = input.at(i);
                    if(c == '('){
                        ++count;
                    }
                    if(c == ')'){
                        --count;
                        if(count == 0){
                            break;
                        }
                    }
                    temp += c;
                    ++i;
                }
                if(i == len){
                    throw INVALID;
                }
                //adds the expression to the output:
                output.push(this->addParenthesis(temp));
                continue;
            }
            //actions
            if((c=='+')||(c=='-')||(c=='*')||(c=='/')){
                output.push(pair<DetailType,string>(ACTION,string()+c));
                continue;
            }
            //only double acts:
            if((c == '|')||(c == '&')){
                if(input.at(++i) == c){
                    output.push(pair<DetailType,string>(ACTION,string()+c+c));
                    continue;
                }
            }
            // '!=':
            if((c == '!') &&(input.at(++i) == '=')){
                output.push(pair<DetailType,string>(ACTION,"!="));
                continue;
            }
        }
    } catch (char const * s){
        throw s;
    } catch (...) {
        throw INVALID;
    }
    return output;
}

pair<DetailType, string> Calculator::addParenthesis(string input) {
    //calculates:
    double d = this->calculate(input);
    //saves the result:
    this->parenthesis.insert(pair<unsigned int,double >(this->lastParenthesis,d));
    return pair<DetailType, string>(PARENTHESIS,to_string(this->lastParenthesis++));
}

Calculator::Calculator(SymbolTable *s) {
    this->variables = s;
    this->lastParenthesis = 0;

    //precedence of opertor:
    this->precedence.insert(pair<string,int>("*",5));
    this->precedence.insert(pair<string,int>("/",5));
    this->precedence.insert(pair<string,int>("+",4));
    this->precedence.insert(pair<string,int>("-",4));
    this->precedence.insert(pair<string,int>("<",3));
    this->precedence.insert(pair<string,int>("<=",3));
    this->precedence.insert(pair<string,int>(">",3));
    this->precedence.insert(pair<string,int>(">=",3));
    this->precedence.insert(pair<string,int>("==",2));
    this->precedence.insert(pair<string,int>("!=",2));
    this->precedence.insert(pair<string,int>("&&",1));
    this->precedence.insert(pair<string,int>("||",0));
}

Expression *Calculator::getExpression(stack<pair<DetailType, string>> &stk) {
    //returns the front's expression:
    pair<DetailType, string> p = stk.top();
    stk.pop();
    switch (p.first){
        case ACTION:{
            Expression* e2 = this->getExpression(stk);
            Expression* e1 = this->getExpression(stk);
            return this->factory.create(p.second,e1,e2);
        }
        case VARIABLE:{
            return new Var(this->variables->at(p.second)->calculate());
        }
        case NUMBER:{
            return new Var(stod(p.second));
        }
        case PARENTHESIS:{
            return new Var(this->parenthesis.at(stoul(p.second)));
        }
        //won't happened:
        default:{
            throw WHAT;
        }
    }
}

stack<pair<DetailType, string>> Calculator::prefix(queue<pair<DetailType, string>> &input) {
    //the algorithm:
    //the queue is stack -> prefix, not postfix
    stack<pair<DetailType, string>> que;
    stack<pair<DetailType, string>> stk;
    while(!input.empty()){
        pair<DetailType, string> token = input.front();
        input.pop();
        if(token.first == ACTION){
            pair<DetailType, string> top;
            while (!stk.empty()){
                top = stk.top();
                if(this->precedence.at(token.second) <= this->precedence.at(top.second)){
                    que.push(top);
                    stk.pop();
                } else {
                    break;
                }
            }
            stk.push(token);
        }
        else{
            que.push(token);
        }
    }
    while (!stk.empty()){
        que.push(stk.top());
        stk.pop();
    }
    return que;
}

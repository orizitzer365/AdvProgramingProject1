#include "Lexer.h"
#include <fstream>
#include <sstream>
#include <queue>

vector<vector<string>> Lexer::lexer(string fileName) {
    ifstream in(fileName);
    if(!in.is_open()){
        return vector<vector<string>>();
    }
    set<string> names = this->makeSet();
    string line;
    string tmp;
    string word;
    string last_word;
    vector<vector<string>> output;
    while (!getline(in,line).eof()){
        vector<string> vecLine;
        //empty line:
        if(line.empty()){
            output.push_back(vecLine);
            continue;
        }
        //splits the line into queue:
        istringstream ss(line + " #@$%#@");
        queue<string> que;
        ss >> tmp;
        while(tmp.compare("#@$%#@") != 0){
            que.push(tmp);
            ss >> tmp;
        }
        //the first word:
        word = que.front();
        que.pop();
        vecLine.push_back(word);
        //if the first word is var:
        if(word.compare("var") == 0){
            if(que.empty()){
                output.push_back(vecLine);
                continue;
            }
            word = que.front();
            que.pop();
            vecLine.push_back(word);
        }
        //checks vars:
        if(names.find(word) == names.end()){
            if(que.empty()){
                output.push_back(vecLine);
                continue;
            }
            //the '=':
            vecLine.push_back(que.front());
            que.pop();
            if(que.empty()){
                output.push_back(vecLine);
                continue;
            }
            //the expression or bind:
            word = que.front();
            que.pop();
            if(word.compare("bind") == 0){
                vecLine.push_back(word);
                if(que.empty()){
                    output.push_back(vecLine);
                    continue;
                }
                //the expression:
                word = que.front();
                que.pop();
            }
        } else{
            //commands:
            //gets the expression:
            if(que.empty()){
                output.push_back(vecLine);
                continue;
            }
            //the expression:
            word = que.front();
            que.pop();
        }
        //checks expressions:
        last_word = word;
        while(!que.empty()){
            //gets new word:
            word = que.front();
            que.pop();
            if(this->add(last_word,word)){
                continue;
            }
            vecLine.push_back(last_word);
            last_word = word;
        }
        vecLine.push_back(last_word);
        output.push_back(vecLine);
    }
    in.close();
    return output;
}

set<string> Lexer::makeSet() {
    return {"openDataServer","connect","while","print","placement","if","sleep"};
}

bool Lexer::add(string &last, string &word) {
    if(last.empty()){
        last = word;
        return true;
    }
    //first check: if '(' > ')' so add:
    int count = 0;
    for(char c : last){
        if(c == '('){
            ++count;
        }
        if(c == ')'){
            --count;
        }
    }
    if (count != 0){
        last += word;
        return true;
    }
    //second check: operator at end of last:
    char c = last.at(last.size()-1);
    if((c =='+')||(c == '-')||(c == '*')||(c == '/')||
       (c == '<')||(c == '>')||(c == '=')||(c == '&')||(c == '|')){
        last += word;
        return true;
    }
    //last check: operator at start of last:
    c = word.at(0);
    if((c =='+')||(c == '-')||(c == '*')||(c == '/')||
       (c == '<')||(c == '>')||(c == '=')||(c == '&')||(c == '|')){
        last += word;
        return true;
    }
    //not adding:
    //removing ',':
    if(word.at(0) == ','){
        string newWord;
        for (int i =1;i<word.size();i++){
            newWord += word.at(i);
        }
        word = newWord;
    }
    return false;
}
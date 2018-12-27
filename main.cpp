#include <iostream>
#include "Lexer.h"
#include "Parser.h"

int main(int argc , char * argv[]) {
    try {
        SymbolTable* vars = new SymbolTable();
        Lexer lex ;
        Calculator calculator(vars);
        if(argc != 2)
            throw "Error no file";
        vector<vector<string>> lines=lex.lexer(argv[1]);
        Parser parser(vars);
        parser.parse(lines);
    }catch (exception& e){
        cout<<e.what()<<endl;
    }catch (char* c){
        cout<<*c<<endl;
    }

    return 0;
}

#include <iostream>
#include "Lexer.h"
#include "Parser.h"

int main(int argc , char * argv[]) {
    try {
        SymbolTable vars ();
        Lexer lex();
        vector<vector<string>> lines;
        if(argc==1){
            string buffer;
            cin>>buffer;
            lines = lex.lexer();
        } else {
            lines = lex.lexer(ofstream(argv[2]));
        }
        Parser parser(vars);
        parser.parse(lines);
    }catch (exception& e){
        cout<<e.what()<<endl;
    }

    return 0;
}

#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include "WordList.h"

class Parser {
    public:
        Parser();
        Parser(WordList*);
        WordList* getComandos();
        Command* generaComando();
    private:
        WordList* comandos;
};

Parser::Parser(){
    comandos=new WordList;
}


WordList* Parser::getComandos(){
    return comandos;
}

Command* Parser::generaComando(){
    std::string instruccion, primera, segunda;
    std::cout << ">>>>";
    std::getline(std::cin, instruccion);
    std::stringstream sstr(instruccion);
    sstr >> primera;
    sstr >> segunda;
    sstr.ignore();
    Command* com=comandos->getCommand(primera);
    if(com){
        com->setNextWord(segunda);
    }
    return com;
}

#endif //PARSER_H
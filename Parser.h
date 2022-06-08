#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include "WordList.h"

class Parser {
    public:
        Parser();
        Parser(WordList*);
        WordList* getComands();
        Command* generateCommand();
    private:
        WordList* comands;
};

Parser::Parser(){
    comands=new WordList;
}


WordList* Parser::getComands(){
    return comands;
}

Command* Parser::generateCommand(){
    std::string instruccion, primera, segunda;
    std::cout << ">>>>";
    std::getline(std::cin, instruccion);
    std::stringstream sstr(instruccion);
    sstr >> primera;
    sstr >> segunda;
    sstr.ignore();
    Command* com=comands->getCommand(primera);
    if(com){
        com->setNextWord(segunda);
    }
    return com;
}

#endif //PARSER_H
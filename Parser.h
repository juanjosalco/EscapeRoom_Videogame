#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include "ListaPalabras.h"

class Parser {
    public:
        Parser();
        Parser(ListaPalabras*);
        ListaPalabras* getComandos();
        Comando* generaComando();
    private:
        ListaPalabras* comandos;
};

Parser::Parser(){
    comandos=new ListaPalabras;
}


ListaPalabras* Parser::getComandos(){
    return comandos;
}

Comando* Parser::generaComando(){
    std::string instruccion, primera, segunda;
    std::cout << ">>>>";
    std::getline(std::cin, instruccion);
    std::stringstream sstr(instruccion);
    sstr >> primera;
    sstr >> segunda;
    sstr.ignore();
    Comando* com=comandos->getComando(primera);
    if(com){
        com->setSegPalabra(segunda);
    }
    return com;
}

#endif //PARSER_H
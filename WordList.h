#ifndef LISTAPALABRAS_H
#define LISTAPALABRAS_H
#include <iostream>
#include <vector>
#include <string>
#include "Command.h"
class WordList{
    public:
        WordList();
        void addCommand(std::string, Command*);
        int isCommad(std::string);
        Command* getCommand(std::string);
        std::string allCommand();

    private:
        std::vector <std::string> palabras;
        std::vector <Command*> comandos;
};


#endif //ListaPalabras_H
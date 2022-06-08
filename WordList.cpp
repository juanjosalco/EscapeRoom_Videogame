#include <iostream>
#include "WordList.h"

WordList::WordList(){}

void WordList::addCommand(std::string pal, Command* com){
    palabras.push_back(pal);
    comandos.push_back(com);
}

int WordList::isCommad(std::string pal){
    for(int i=0; i<palabras.size(); i++){
        if (palabras[i]==pal){
            return i;
        }
    }
    return -1;
}

Command* WordList::getCommand(std::string pal){
    int pos=isCommad(pal);
    if(pos>=0){
        return comandos[pos];
    }
    return nullptr;
}

std::string WordList::allCommand(){
    std::string todos="Los comandos que puedes usar son:\n";
    for(std::string &pal : palabras){
        todos += "\t"+ pal + "\n";
    }
    todos+= "\t->El comand va seguido de una segunda palabra\n\t->Solo el comando ayuda es de una sola palabra.";
    return todos;
}

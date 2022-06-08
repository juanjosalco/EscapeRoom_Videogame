#ifndef LISTAPALABRAS_H
#define LISTAPALABRAS_H
#include <iostream>
#include <vector>
#include <string>

class ListaPalabras{
    public:
        ListaPalabras();
        void agregaComando(std::string, Command*);
        int esComando(std::string);
        Command* getCommand(std::string);
        std::string todosLosComandos();

    private:
        std::vector <std::string> palabras;
        std::vector <Command*> comandos;
};

ListaPalabras::ListaPalabras(){}

void ListaPalabras::agregaComando(std::string pal, Command* com){
    palabras.push_back(pal);
    comandos.push_back(com);
}

int ListaPalabras::esComando(std::string pal){
    for(int i=0; i<palabras.size(); i++){
        if (palabras[i]==pal){
            return i;
        }
    }
    return -1;
}

Command* ListaPalabras::getCommand(std::string pal){
    int pos=esComando(pal);
    if(pos>=0){
        return comandos[pos];
    }
    return nullptr;
}

std::string ListaPalabras::todosLosComandos(){
    std::string todos="Los comandos que puedes usar son:\n";
    for(std::string &pal : palabras){
        todos += "\t"+ pal + "\n";
    }
    todos+= "\t->El comand va seguido de una segunda palabra\n\t->Solo el comand ayuda es de una sola palabra.";
    return todos;
}

#endif //ListaPalabras_H
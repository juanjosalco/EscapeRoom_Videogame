#ifndef DESPLAZACOMANDO_H
#define DESPLAZACOMANDO_H
#include <iostream>
#include "Character.h"
#include "Command.h"

class DesplazaComando:public Command{
    public:
        DesplazaComando(Character*);
        void run();
    private:
        Character* jugador;
};

DesplazaComando::DesplazaComando(Character* personaje):Command("desplaza", ""){
    jugador=personaje;
}

void DesplazaComando::run(){
    if (!hasNextWord()){
        std::cout<<"A donde quieres ir?... sin direccion no puedo ayudarte..." << std::endl;
    }
    else{
        std::string direc = getNextWord();
        if (jugador->camina(direc)){
            Zone* actual=jugador->getPosition();
            std::cout << "Te has movido hacia el " << direc << std::endl;
            std::cout << "Ahora estas en: " << actual->getDescription() << std::endl;
        }
        else{
            std::cout << "No hay salida en esa direccion o no tienes la llave para abrir, busca otra salida... o la llave..." << std::endl;
        }
    }
}

#endif //DESPLAZACOMANDO_H
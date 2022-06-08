#ifndef DESPLAZACOMANDO_H
#define DESPLAZACOMANDO_H
#include <iostream>
#include "Character.h"
#include "Comando.h"

class DesplazaComando:public Comando{
    public:
        DesplazaComando(Character*);
        void ejecuta();
    private:
        Character* jugador;
};

DesplazaComando::DesplazaComando(Character* personaje):Comando("desplaza", ""){
    jugador=personaje;
}

void DesplazaComando::ejecuta(){
    if (!tieneSegPalabra()){
        std::cout<<"A donde quieres ir?... sin direccion no puedo ayudarte..." << std::endl;
    }
    else{
        std::string direc = getSegPalabra();
        if (jugador->camina(direc)){
            Zone* actual=jugador->getPosicion();
            std::cout << "Te has movido hacia el " << direc << std::endl;
            std::cout << "Ahora estas en: " << actual->getDescription() << std::endl;
        }
        else{
            std::cout << "No hay salida en esa direccion o no tienes la llave para abrir, busca otra salida... o la llave..." << std::endl;
        }
    }
}

#endif //DESPLAZACOMANDO_H
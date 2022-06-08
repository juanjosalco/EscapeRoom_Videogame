#ifndef TOMACOMANDO_H
#define TOMACOMANDO_H
#include "Character.h"
#include "Item.h"
#include "Comando.h"
class TomaComando:public Comando{
    public:
        TomaComando(Character*);
        void ejecuta();
    private:
        Character* jugador;
};

TomaComando::TomaComando(Character* personaje):Comando("Toma", ""){
    jugador=personaje;
}

void TomaComando::ejecuta(){
    if (!tieneSegPalabra()){
        std::cout<<"Que quieres tomar de la habitación?...\n" << "no puedo ayudarte si no me das toda la información..." << std::endl;
    }
    else{
        std::string cosa = getSegPalabra();
        Room* actual= jugador->getPosicion();
        int num=actual->buscaItem(cosa); //veo si está en el cuarto (posicion dentro del vector)
        if (num!=-1){
            Item* paraJugador=actual->getItem(num);
            jugador->agregaItem(paraJugador);
            actual->sacaItem(num);
            std::cout << "Ahora tienes en tu poder: "<< std::endl;
            std::cout << paraJugador->getDescripcionLarga() << std::endl;
        }
        else{
            std::cout<< "Ese objeto no se encuentra en esta habitacion..."<<std::endl;
            std::cout << "Recuerda tu estas aqui: " << std::endl;
            actual->descripcionLarga();
        }
    }
}


#endif //TOMACOMANDO_H
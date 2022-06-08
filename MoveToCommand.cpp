#include "MoveToCommand.h"

MoveToCommand::MoveToCommand(Character* character):Command("desplaza", ""){
    player=character;
}

void MoveToCommand::run(){
    if (!hasNextWord()){
        std::cout<<"A donde quieres ir?... sin direccion no puedo ayudarte..." << std::endl;
    }
    else{
        std::string direc = getNextWord();
        if (player->camina(direc)){
            Zone* actual=player->getPosition();
            std::cout << "Te has movido hacia el " << direc << std::endl;
            std::cout << "Ahora estas en: " << actual->getDescription() << std::endl;
        }
        else{
            std::cout << "No hay salida en esa direccion o no tienes la llave para abrir, busca otra salida... o la llave..." << std::endl;
        }
    }
}
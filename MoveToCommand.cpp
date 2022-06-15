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
        Zone* actual= player->getPosition();
        for (int i = 0; i <5; i++)
        {
           
        }
        

    }
}
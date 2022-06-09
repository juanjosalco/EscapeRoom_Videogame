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
    }
}

#include "TakeCommand.h"

TakeCommand::TakeCommand(Character* character):Command("Take", ""){
    player=character;
}

void TakeCommand::run(){
    if (!hasNextWord()){
        std::cout<<"Que quieres tomar de la habitación?...\n" << "no puedo ayudarte si no me das toda la información..." << std::endl;
    }
    else{
        std::string thing = getNextWord();
        Zone* actual= player->getPosition();
        int num=actual->buscaItem(thing); //veo si está en el cuarto (posicion dentro del vector)
        if (num!=-1){
            Item* forPlayer=actual->getItem(num);
            player->agregaItem(forPlayer);
            actual->sacaItem(num);
            std::cout << "Ahora tienes en tu poder: "<< std::endl;
            std::cout << forPlayer->getDescription() << std::endl;
        }
        else{
            std::cout<< "Ese objeto no se encuentra en esta habitacion..."<<std::endl;
            std::cout << "Recuerda tu estas aqui: " << std::endl;
            actual->getDescription();
        }
    }
}
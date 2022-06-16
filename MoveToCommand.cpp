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
        std::vector <Zone*> zonas=actual->getZones();
        for (int i = 0; i <zonas.size(); i++)
        {
           if (zonas[i]->getName()==direc)
           {
            player->setPosition(zonas[i]);
            std::cout<<"Ahora estas en: "<<zonas[i]->getName()<<"\n"<<zonas[i]->getDescription()<<std::endl;
           }
           
        }
        

    }
}
#include "UseCommand.h"

UseCommand::UseCommand(Character* character):Command("use", ""){
    player=character;
}

void UseCommand::run(){
    if (!hasNextWord()){
        std::cout<<"¿Qué quieres usar?... sin especificar no puedo ayudarte..." << std::endl;
    }
    else{
        std::string thing = getNextWord();
        std::vector<Item*> inventory = player->getInventory();
        Zone* local = player->getPosition();
        for (int i = 0; i < inventory.size(); i++)
        {
           if (inventory[i]->getName()==thing){
                if(local->getZoneId() == inventory[i]->getPieceId()){

                }else{
                    std::cout<<"Este Item no funciona aquí "<<std::endl;
                }   
           }
        }
    }
}

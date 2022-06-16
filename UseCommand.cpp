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
        std::vector <Item*> itemzz=local->getItems();
        for (int i = 0; i < inventory.size(); i++)
        {
           if (inventory[i]->getName()==thing){
                if(local->getZoneId() == inventory[i]->getPieceId()){
                    inventory[i]->setUses(false);
                    for (int i = 0; i < itemzz.size(); i++)
                    {
                        itemzz[i]->setBlock(false);
                    }
                    std::cout << "Item elegido usado correctamente" << std::endl;  

                }else{
                    std::cout<<"Este Item no funciona aquí "<<std::endl;
                }   
           }
        }
    }
}

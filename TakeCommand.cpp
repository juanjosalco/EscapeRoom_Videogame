
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
        std::vector <Item*> itemsz=actual->getItems();
        
        
        int num=actual->searchItem(thing); //veo si está en el cuarto (posicion dentro del vector)
        if (num!=-1){
            
            if (itemsz[num]->getBlock())
            {
                std::cout<<"No puedes tomar este item parece que necesitas otro item para acceder "<<std::endl;
            }
            else{
                player->addItem(itemsz[num]);
                actual->sacaItem(num);            
                std::cout << "Ahora tienes en tu poder: "<< std::endl;
                std::cout << itemsz[num]->getDescripcionLarga() << std::endl;
            if (itemsz[num]->getName()=="nota_final"||itemsz[num]->getName()=="nota_final_alter"){
               exit(0);
            }
            }
        }
        else{
            std::cout<< "Ese objeto no se encuentra en esta habitacion..."<<std::endl;
            std::cout << "Recuerda tu estas aqui: " << std::endl;
            std::cout<<actual->getName()<<std::endl;
            std::cout<<"En esta zona hay:"<<std::endl;
            for (int i = 0; i < itemsz.size(); i++)
            {
                std::cout<<itemsz[i]->getName()<<std::endl;
            }
            
        }
    }
}
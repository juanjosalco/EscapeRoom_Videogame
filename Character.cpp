#include <iostream>
#include "Character.h"

Character::Character(){
    position=nullptr;
    name="Personaje";
    numItems=0;
}

Character::Character(std::string name_){
    position=nullptr;
    name=name_;
    numItems=0;
}

std::string Character::getName() const{
    return name;
}


void Character::setName(std::string name_){
    name=name_;
}


Zone* Character::getPosition() const{
    return position;
}

void Character::setPosition(Zone* nuevo){
    position=nuevo;
}
        
void Character::addItem(Item* item){
    inventory.push_back(item);
}

bool Character::searchItem(std::string cosa){
    for(int i=0; i<numItems; i++){
        if (inventory[i]->getDescription()==cosa){
            return true;
        }
    }
    return false;
}

std::vector<Item*> Character::getInventory(){
    return inventory;
}

std::string Character::getItemsNames(){
    std::string nombres;
    for (int i = 0; i < inventory.size(); i++)
    {
        nombres=nombres+inventory[i]->getName()+"\n";
    }
    return nombres;
}

std::ostream &operator << (std::ostream & salida, Character& player_){    
    salida<<"Eres: "<<player_.getName()<<"\nTienes: \n"<<player_.getItemsNames()<<"\n";
    return salida;
}
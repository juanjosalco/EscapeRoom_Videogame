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

void Character::display(){
    std::cout << "Soy " << name << std::endl;
    std::cout << "y llevo en mi bolsa "<< numItems << "objetos recolectados." << std::endl;
}

std::vector<Item*> Character::getInventory(){
    return inventory;
}
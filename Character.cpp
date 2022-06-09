#include <iostream>
#include "Character.h"

Character::Character(){
    position=nullptr;
    name="Personaje";
    numItems=0;
}

Character::Character(std::string name){
    position=nullptr;
    name=name;
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
        
void Character::agregaItem(Item* item){
    if (numItems<11){
        inventario[numItems++]=item;
    }
    else{
        std::cout << "Tu bolsa esta llena viajero, no puedes guardar este artículo..."<<std::endl;
    }
}

bool Character::buscaItem(std::string cosa){
    for(int i=0; i<numItems; i++){
        if (inventario[i]->getDescription()==cosa){
            return true;
        }
    }
    return false;
}

void Character::imprime(){
    std::cout << "Soy " << name << std::endl;
    std::cout << "y llevo en mi bolsa "<< numItems << "objetos recolectados." << std::endl;
}


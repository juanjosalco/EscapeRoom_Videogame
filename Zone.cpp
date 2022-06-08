#include <iostream>
#include <vector>
#include "Zone.h"

Zone::Zone(){
    description="Es una habitacion sin nombre";
    for (int i=0; i<5; i++){
        zones[i]=nullptr;
    }
}
Zone::Zone(std::string desc){
    description=desc;
    for (int i=0; i<5; i++){
        zones[i]=nullptr;
    }
}

std::string Zone::getDescription(){
    return description;
}

Item* Zone::getItem(int num){
    if (num>=0 && num<items.size()){
        return items[num];
    }
    return nullptr;
}

void Zone::agregaItem(Item* thing){
    items.push_back(thing);
}
int Zone::buscaItem(std::string what){
    for(int i=0; i<items.size();i++){
        if(items[i]->getDescription()==what){
            return i; //devuelve la posición donde está ese objeto
        }
    }
    return -1; //regresa -1 si no encontró ese item
}

void Zone::sacaItem(int pos){
    items.erase(items.begin()+pos); //Borra el de la posicion pos del vector
}
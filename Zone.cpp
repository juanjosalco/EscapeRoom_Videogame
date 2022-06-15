#include <iostream>
#include <vector>
#include "Zone.h"

Zone::Zone(){
    description="Es una habitacion sin nombre";
    for (int i=0; i<5; i++){
        zones[i]=nullptr;
    }
}
Zone::Zone(std::string name_,std::string desc, int zoneId_){
    name=name_;
    description=desc;
    zoneId = zoneId_;
}

void Zone::setZonez(Zone* zon){
    zones.push_back(zon);
}

std::string Zone::getName(){
    return name;    
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

int Zone::getZoneId(){
    return zoneId;
}

std::vector <Item*> Zone::getItems(){
    return items;
}

std::vector <Zone*> Zone::getZones(){
    return zones;
}

void Zone::addItem(Item* thing){
    items.push_back(thing);
}
int Zone::searchItem(std::string what){
    for(int i=0; i<items.size();i++){
        if(items[i]->getName()==what){
            return i; //devuelve la posición donde está ese objeto
        }
    }
    return -1; //regresa -1 si no encontró ese item
}

void Zone::sacaItem(int pos){
    items.erase(items.begin()+pos); //Borra el de la posicion pos del vector
}
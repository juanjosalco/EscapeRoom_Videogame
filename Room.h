#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <vector>
#include "Item.h"

class Room {
    public:
        Room();
        Room(std::string, bool);
        std::string getDescripcion();
        Room* getSalida(std::string);
        int numSalida(std::string);
        void setSalidas(Room*, Room*, Room*, Room*);
        Item* getItem(int);
        void sacaItem(int);
        void agregaItem(Item*);
        int buscaItem(std::string);
        void descripcionLarga();
        bool requiereLlave();
    private:
        std::string descripcion;
        std::vector<Item*> cosas;
        Room* salidas[4];
        bool tieneLlave;
};
Room::Room(){
    descripcion="Es una habitacion sin nombre";
    for (int i=0; i<4; i++){
        salidas[i]=nullptr;
    }
    tieneLlave=false;
}
Room::Room(std::string desc, bool cerrado){
    descripcion=desc;
    for (int i=0; i<4; i++){
        salidas[i]=nullptr;
    }
    tieneLlave=cerrado;
}

Room* Room::getSalida(std::string dir){
    int num=numSalida(dir);
    if(num>=0){
        return salidas[num];
    }
    return nullptr;
}

void Room::setSalidas(Room* n, Room* s, Room* e, Room* o){
    salidas[0]=n;
    salidas[1]=s;
    salidas[2]=e;
    salidas[3]=o;
}

std::string Room::getDescripcion(){
    return descripcion;
}

Item* Room::getItem(int num){
    if (num>=0 && num<cosas.size()){
        return cosas[num];
    }
    return nullptr;
}
bool Room::requiereLlave(){
    return tieneLlave;
}

void Room::agregaItem(Item* cosita){
    cosas.push_back(cosita);
}
int Room::buscaItem(std::string que){
    for(int i=0; i<cosas.size();i++){
        if(cosas[i]->getDescripcion()==que){
            return i; //devuelve la posición donde está ese objeto
        }
    }
    return -1; //regresa -1 si no encontró ese item
}

void Room::sacaItem(int pos){
    cosas.erase(cosas.begin()+pos); //Borra el de la posicion pos del vector
}

void Room::descripcionLarga(){
    std::cout << descripcion << std::endl;
    std::cout << "Dentro de esta habitacion enigmatica tenemos: " << std::endl;
    for (int i=0; i<cosas.size(); i++){
        std::cout << cosas[i]->getDescripcion() << std::endl;
    }
}

int Room::numSalida(std::string dir){
    if (dir=="norte"){
        return 0;
    }
    if (dir=="sur"){
        return 1;
    }
    if (dir=="este"){
        return 2;
    }
    if (dir=="oeste"){
        return 3;
    }
    return -1;
}

#endif //ROOM_H
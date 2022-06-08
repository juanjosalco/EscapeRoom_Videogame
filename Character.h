#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include "Room.h"

class Character {
    public:
        Character();
        Character(std::string, int);
        std::string getNombre() const;
        int getHp() const;
        void setNombre(std::string);
        void setHp(int);
        void actualizaHp(int);
        Room* getPosicion() const;
        void setPosicion(Room*);
        void agregaItem(Item*);
        Item* consultaItem(int pos) const;
        void imprime();
        bool camina(std::string);
        bool buscaItem(std::string);
        //virtual void ataque(Personaje&);
    private:
        std::string nombre;
        int hp;
        Room* posicion;
        Item* inventario[5];
        int numItems;
};

Character::Character(){
    posicion=nullptr;
    nombre="Personaje";
    hp=100;
    numItems=0;
}

Character::Character(std::string name, int pts){
    posicion=nullptr;
    nombre=name;
    hp=pts;
    numItems=0;
}

std::string Character::getNombre() const{
    return nombre;
}

int Character::getHp() const{
    return hp;
}

void Character::setNombre(std::string name){
    nombre=name;
}

void Character::setHp(int pts){
    hp=pts;
}


void Character::actualizaHp(int pts){
    hp+=pts;
}

Room* Character::getPosicion() const{
    return posicion;
}

void Character::setPosicion(Room* nuevo){
    posicion=nuevo;
}
        
void Character::agregaItem(Item* item){
    if (numItems<5){
        inventario[numItems++]=item;
    }
    else{
        std::cout << "Tu bolsa esta llena viajero, no puedes guardar este artículo..."<<std::endl;
    }
}

bool Character::buscaItem(std::string cosa){
    for(int i=0; i<numItems; i++){
        if (inventario[i]->getDescripcion()==cosa){
            return true;
        }
    }
    return false;
}

bool Character::camina(std::string dir){
    Room* voyA=posicion->getSalida(dir);
    if (voyA!=nullptr && !voyA->requiereLlave()){
        setPosicion(voyA);
        return true;
    }
    else if (voyA!=nullptr && voyA->requiereLlave()){
        if (buscaItem("Llave")){
            setPosicion(voyA);
            return true;
        }
    }
    return false;
}

void Character::imprime(){
    std::cout << "Soy " << nombre << " actualmente tengo " << hp << "  de hp" << std::endl;
    std::cout << "y llevo en mi bolsa "<< numItems << "objetos recolectados." << std::endl;
}



#endif //CHARACTER_H
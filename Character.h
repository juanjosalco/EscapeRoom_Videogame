#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include "Zone.h"

class Character {
    public:
        Character();
        Character(std::string, int);
        std::string getNombre() const;
        int getHp() const;
        void setNombre(std::string);
        void setHp(int);
        void actualizaHp(int);
        Zone* getPosicion() const;
        void setPosicion(Zone*);
        void agregaItem(Item*);
        Item* consultaItem(int pos) const;
        void imprime();
        bool camina(std::string);
        bool buscaItem(std::string);
        //virtual void ataque(Personaje&);
    private:
        std::string nombre;
        int hp;
        Zone* posicion;
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

Zone* Character::getPosicion() const{
    return posicion;
}

void Character::setPosicion(Zone* nuevo){
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
        if (inventario[i]->getDescription()==cosa){
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
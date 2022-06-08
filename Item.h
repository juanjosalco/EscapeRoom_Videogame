#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <iostream>

class Item {
    public:
        Item();
        Item(std::string, int);
        std::string getDescripcion() const;
        int getPeso() const;
        void setDescripcion(std::string);
        void setPeso(int);
        std::string getDescripcionLarga();
        
    private:
        std::string descripcion;
        int peso;
};

Item::Item(){
    descripcion="Este es una cosita bonita";
    peso=1;
}

Item::Item(std::string desc, int pes){
    descripcion=desc;
    peso=pes;
}

int Item::getPeso() const{
    return peso;
}

std::string Item::getDescripcion() const{
    return descripcion;
}

void Item::setPeso(int pes){
    peso=pes;
}

void Item::setDescripcion(std::string descp){
    descripcion=descp;
}

std::string Item::getDescripcionLarga(){
    return descripcion + " y pesa " + std::to_string(peso);
}

#endif //ITEM_H
#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include "Zone.h"

class Character {
    public:
        Character();
        Character(std::string);
        std::string getName() const;
        void setName(std::string);
        Zone* getPosition() const;
        void setPosition(Zone*);
        void agregaItem(Item*);
        Item* consultaItem(int pos) const;
        void imprime();
        bool camina(std::string);
        bool buscaItem(std::string);
        //virtual void ataque(Personaje&);
    private:
        std::string name;
        Zone* position;
        Item* inventario[11];
        int numItems;
};


#endif //CHARACTER_H
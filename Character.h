#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <vector>
#include "Zone.h"

class Character {
    public:
        Character();
        Character(std::string);
        std::string getName() const;
        void setName(std::string);
        Zone* getPosition() const;
        void setPosition(Zone*);
        void addItem(Item*);
        Item* consultItem(int pos) const;
        void display();
        bool searchItem(std::string);
        //virtual void ataque(Personaje&);
    private:
        std::string name;
        Zone* position;
        Item* inventory[11];
        int numItems;
};


#endif //CHARACTER_H
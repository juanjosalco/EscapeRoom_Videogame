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
        std::vector<Item*> getInventory();
        std::string getItemsNames();
        friend std::ostream& operator<< (std::ostream &, Character&);
    private:
        std::string name;
        Zone* position;
        std::vector<Item*> inventory;
        int numItems;
};


#endif //CHARACTER_H
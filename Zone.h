#ifndef ZONE_H
#define ZONE_H

#include <iostream>
#include <vector>
#include "Item.h"

class Zone {
    public:
        Zone();
        Zone(std::string,std::string);
        std::string getName();
        std::string getDescription();
        Item* getItem(int);
        std::vector <Item*> getItems();
        void sacaItem(int);
        void addItem(Item*);
        int searchItem(std::string);
        void descripcionLarga();
    private:
        std::string name;
        std::string description;
        std::vector<Item*> items;
        Zone* zones[5];
};

#endif //ROOM_H
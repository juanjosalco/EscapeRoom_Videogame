#ifndef ZONE_H
#define ZONE_H

#include <iostream>
#include <vector>
#include "Item.h"

class Zone {
    public:
        Zone();
        Zone(std::string);
        std::string getDescription();
        Item* getItem(int);
        void sacaItem(int);
        void agregaItem(Item*);
        int buscaItem(std::string);
        void descripcionLarga();
    private:
        std::string description;
        std::vector<Item*> items;
        Zone* zones[5];
};

#endif //ROOM_H
#ifndef ZONE_H
#define ZONE_H

#include <iostream>
#include <vector>
#include "Item.h"

class Zone {
    public:
        Zone();
        Zone(std::string,std::string);
        void setZonez(Zone*);
        std::string getName();
        std::string getDescription();
        Item* getItem(int);
        std::vector <Item*> getItems();
        std::vector <Zone*> getZones();
        void sacaItem(int);
        void addItem(Item*);
        int searchItem(std::string);
        void descripcionLarga();
    private:
        std::string name;
        std::string description;
        std::vector<Item*> items;
        std::vector <Zone*> zones;
};

#endif //ROOM_H
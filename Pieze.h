#ifndef PIEZE_H
#define PIEZE_H
#include <iostream>
#include "Item.h"

class Pieze:public Item
{
private:
    int id;
    bool use;
public:
    Pieze();
    Pieze(std::string,std::string,int,bool);
    std::string getDescripcionLarga();
};
#endif //PIEZE_H


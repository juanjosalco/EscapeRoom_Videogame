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
Pieze::Pieze()
{
}

Pieze::Pieze(std::string name_,std::string dest_,int id_,bool use_ ):Item(name_,dest_)
{
    id=id_;
    use=use_;
}


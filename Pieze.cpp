#include <iostream>
#include "Pieze.h"

Pieze::Pieze()
{
}

Pieze::Pieze(std::string name_,std::string dest_,int id_,bool use_ ):Item(name_,dest_)
{
    id=id_;
    use=use_;
}
std::string Pieze::getDescripcionLarga(){
    return Item::getDescripcionLarga()+"\n"+"Usos"+std::to_string(use);
}

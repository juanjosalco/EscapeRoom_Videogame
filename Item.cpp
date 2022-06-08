#include <string>
#include <iostream>
#include "Item.h"


Item::Item(){
    description="Este es una cosita bonita";
    name="";
}

Item::Item(std::string name_, std::string des){
    description=des;
    name=name_;
}

std::string Item::getName()const{
    return name;
}

std::string Item::getDescription() const{
    return description;
}

void Item::setName(std::string name_){
    name=name_;
}

void Item::setDescription(std::string descp){
    description=descp;
}

std::string Item::getDescripcionLarga(){
    return name+ ": \n" + description ;
}

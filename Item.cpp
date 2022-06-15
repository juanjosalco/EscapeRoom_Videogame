#include <string>
#include <iostream>
#include "Item.h"


Item::Item(){
    description="Este es una cosita bonita";
    name="";
}

Item::Item(std::string name_, std::string des,bool block_){
    description=des;
    name=name_;
    block=block_;
}

std::string Item::getName()const{
    return name;
}

std::string Item::getDescription() const{
    return description;
}

bool Item::getBlock()const{
    return block;
}

void Item::setName(std::string name_){
    name=name_;
}

void Item::setDescription(std::string descp){
    description=descp;
}

void Item::setBlock(bool block_){
    block=block_;
}

std::string Item::getDescripcionLarga(){
    return name+ ": \n" + description ;
}

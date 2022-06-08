#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <iostream>

class Item {
    public:
        Item();
        Item(std::string, std::string);
        std::string getDescription() const;
        std::string getName() const;
        void setDescription(std::string);
        void setName(std::string);
        std::string getDescripcionLarga();
        
    private:
        std::string description;
        std::string name;
};

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

#endif //ITEM_H
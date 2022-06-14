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
        virtual std::string getDescripcionLarga()=0;
        
    private:
        std::string description;
        std::string name;
};


#endif //ITEM_H
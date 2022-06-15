#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <iostream>

class Item {
    public:
        Item();
        Item(std::string, std::string,bool);
        std::string getDescription() const;
        std::string getName() const;
        bool getBlock() const;
        void setDescription(std::string);
        void setName(std::string);
        void setBlock(bool);
        virtual std::string getDescripcionLarga()=0;
        virtual int getPieceId();
        
    private:
        std::string description;
        std::string name;
        bool block;
};


#endif //ITEM_H
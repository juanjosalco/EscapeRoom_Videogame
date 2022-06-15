#ifndef PIEZE_H
#define PIEZE_H
#include <iostream>
#include "Item.h"

class Piece:public Item
{
private:
    int id;
    bool use;
public:
    Piece();
    Piece(std::string,std::string,bool,int,bool);
    std::string getDescripcionLarga();
    int getPieceId();
    bool getUse();

};
#endif //PIEZE_H


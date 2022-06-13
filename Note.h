#ifndef NOTE_H
#define NOTE_H
#include <iostream>
#include "Item.h"

class Note: public Item
{
private:
    std::string content;
public:
    Note();
    Note(std::string,std::string,std::string);
    std::string getDescripcionLarga();
};

#endif // NOTE_H
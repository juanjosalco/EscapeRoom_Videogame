#ifndef NOTE_H
#define NOTE_H
#include <iostream>
#include "Item.h"

class Note
{
private:
    std::string content;
public:
    Note();
    Note(std::string);
    std::string getContent();
};

#endif // NOTE_H
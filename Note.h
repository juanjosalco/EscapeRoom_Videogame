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
Note::Note()
{
}

Note::Note(std::string content_)
{
    content=content_;
}

std::string Note::getContent(){
    return content;
}

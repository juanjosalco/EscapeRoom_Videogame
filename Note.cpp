#include "Note.h"

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
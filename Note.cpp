#include "Note.h"

Note::Note()
{
}

Note::Note(std::string name_,std::string dest_,std::string content_):Item(name_,dest_)
{
    content=content_;
}

std::string Note::getDescripcionLarga(){
    return Item::getDescripcionLarga()+"\n"+content;
}
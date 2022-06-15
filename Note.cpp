#include "Note.h"

Note::Note()
{
}

Note::Note(std::string name_,std::string dest_,bool block_,std::string content_):Item(name_,dest_,block_)
{
    content=content_;
}

std::string Note::getDescripcionLarga(){
    return Item::getDescripcionLarga()+"\n"+content;
}
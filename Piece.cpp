#include <iostream>
#include "Piece.h"

Piece::Piece()
{
}

Piece::Piece(std::string name_,std::string dest_,bool block_,int id_,bool use_ ):Item(name_,dest_,block_)
{
    id=id_;
    use=use_;
}
std::string Piece::getDescripcionLarga(){
    return Item::getDescripcionLarga()+"\n"+"Usos: "+std::to_string(use);
}

bool Piece::getUse(){
    return use;
}

int Piece::getPieceId(){
    return id;
}

void Piece::setUse(bool use_){
    use=use_;
}
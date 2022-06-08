#ifndef COMANDO_H
#define COMANDO_H
#include <iostream>
class Comando{
    public:
        Comando();
        Comando(std::string, std::string);
        std::string getComando() const;
        std::string getSegPalabra() const;
        void setSegPalabra(std::string);
        bool desconocido();
        bool tieneSegPalabra();
        virtual void ejecuta() = 0;
    private:
        std::string comando;
        std::string segPalabra;
};

Comando::Comando(){
    comando="";
    segPalabra="";
}

Comando::Comando(std::string com, std::string seg){
    comando=com;
    segPalabra=seg;
}

std::string Comando::getComando() const{
    return comando;
}

std::string Comando::getSegPalabra() const{
    return segPalabra;
}

void Comando::setSegPalabra(std::string seg){
    segPalabra=seg;
}

bool Comando::desconocido(){
    return comando=="";
}

bool Comando::tieneSegPalabra(){
    return segPalabra!="";
}
#endif //COMANDO_H
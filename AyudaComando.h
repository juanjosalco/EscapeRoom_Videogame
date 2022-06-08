#ifndef AYUDACOMANDO_H
#define AYUDACOMANDO_H
#include "Command.h"
#include "ListaPalabras.h"
class AyudaComando:public Command{
    public:
        AyudaComando(ListaPalabras*);
        void run();
    private:
        ListaPalabras* validas;
};

AyudaComando::AyudaComando(ListaPalabras* palabras):Command("Ayuda", ""){
    validas=palabras;
}

void AyudaComando::run(){
    std::cout<< "Estas desamparado en esta casa lugubre y solitaria" << std::endl;
    std::cout << "No sabes que hacer, pero no te preocupes, recuerda...." << std::endl;
    std::cout << validas->todosLosComandos() << std::endl;
}

#endif //AYUDACOMANDO_H
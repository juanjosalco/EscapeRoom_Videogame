#ifndef AYUDACOMANDO_H
#define AYUDACOMANDO_H
#include "Command.h"
#include "WordList.h"
class AyudaComando:public Command{
    public:
        AyudaComando(WordList*);
        void run();
    private:
        WordList* validas;
};

AyudaComando::AyudaComando(WordList* palabras):Command("Ayuda", ""){
    validas=palabras;
}

void AyudaComando::run(){
    std::cout<< "Estas desamparado en esta casa lugubre y solitaria" << std::endl;
    std::cout << "No sabes que hacer, pero no te preocupes, recuerda...." << std::endl;
    std::cout << validas->allCommand() << std::endl;
}

#endif //AYUDACOMANDO_H
#include <iostream>
#include "HelpCommand.h"

HelpCommand::HelpCommand(WordList* words):Command("Ayuda", ""){
    avalible=words;
}

void HelpCommand::run(){
    std::cout<< "Estas desamparado en esta casa lugubre y solitaria" << std::endl;
    std::cout << "No sabes que hacer, pero no te preocupes, recuerda...." << std::endl;
    std::cout << avalible->allCommand() << std::endl;
}
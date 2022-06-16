#include <iostream>
#include "HelpCommand.h"

HelpCommand::HelpCommand(WordList* words):Command("help", ""){
    avalible=words;
}

void HelpCommand::run(){
    std::cout << "No sabes que hacer, pero no te preocupes, recuerda...." << std::endl;
    std::cout << avalible->allCommand() << std::endl;
}
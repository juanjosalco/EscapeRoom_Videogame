#include "Parser.h"

Parser::Parser(){
    comands=new WordList;
}


WordList* Parser::getComands(){
    return comands;
}

Command* Parser::generateCommand(){
    std::string instruction, first, second;
    bool good=true;
    while (good){
        std::cout << ">>>>";
        std::getline(std::cin, instruction);
        std::stringstream sstr(instruction);
        sstr >> first;
        sstr >> second;
        sstr.ignore();
        Command* com=comands->getCommand(first);
        try  {
        Command* com=comands->getCommand(first);
        if(com){
            com->setNextWord(second);
            good=false;
            return com;
        } else {
            throw com;
        }
        }
        catch (Command* error)  {
            std::cout << "Debes ingresar un comando válido\n";
        }
    }
    
    
}


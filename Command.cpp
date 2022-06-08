
#include <iostream>
#include "Command.h"

Command::Command(){
    command="";
    nextWord="";
}

Command::Command(std::string com, std::string seg){
    command=com;
    nextWord=seg;
}

std::string Command::getCommand() const{
    return command;
}

std::string Command::getNextWord() const{
    return nextWord;
}

void Command::setNextWord(std::string seg){
    nextWord=seg;
}

bool Command::unknown(){
    return command=="";
}

bool Command::hasNextWord(){
    return nextWord!="";
}
#include <iostream>
#include <stdlib.h>
#include "ExitCommand.h"

ExitCommand::ExitCommand(Character* player_):Command("inventory", ""){
    Invent=player_;
}

void ExitCommand::run(){
    exit(0);
}
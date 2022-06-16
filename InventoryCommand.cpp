#include <iostream>
#include "InventoryCommand.h"

InventoryCommand::InventoryCommand(Character* player_):Command("inventory", ""){
    Invent=player_;
}

void InventoryCommand::run(){
    std::cout<<Invent<< std::endl;

}
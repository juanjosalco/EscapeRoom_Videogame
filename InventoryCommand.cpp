#include <iostream>
#include "InventoryCommand.h"

InventoryCommand::InventoryCommand(Character* player_):Command("inventory", ""){
    Invent=player_;
}

void InventoryCommand::run(){
    Character inven=*Invent;
    std::cout<<inven<< std::endl;

}
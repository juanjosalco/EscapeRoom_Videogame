#ifndef INVETORYCOMMAND_H
#define INVETORYCOMMAND_H
#include "Command.h"
#include "Character.h"
class InventoryCommand:public Command{
    public:
        InventoryCommand(Character*);
        void run();
    private:
        Character* Invent;
};


#endif //INVETORYCOMMAND_H
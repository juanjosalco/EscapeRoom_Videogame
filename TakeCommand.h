#ifndef TAKECOMMAND_H
#define TAKECOMMAND_H

#include "Character.h"
#include "Item.h"
#include "Command.h"

class TakeCommand:public Command{
    public:
        TakeCommand(Character*);
        void run();
    private:
        Character* player;
};

#endif //TAKECOMMAND_H
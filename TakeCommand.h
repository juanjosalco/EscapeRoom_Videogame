#ifndef TOMACOMANDO_H
#define TOMACOMANDO_H

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

#endif //TOMACOMANDO_H
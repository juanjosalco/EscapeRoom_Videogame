#ifndef MOVE_TO_COMMAND_H
#define MOVE_TO_COMMAND_H
#include <iostream>
#include "Character.h"
#include "Command.h"

class MoveToCommand:public Command{
    public:
        MoveToCommand(Character*);
        void run();
    private:
        Character* player;
};

#endif //DESPLAZACOMANDO_H
#ifndef USE_COMMAND_H
#define USE_COMMAND_H
#include <iostream>
#include "Character.h"
#include "Piece.h"
#include "Command.h"

class UseCommand:public Command{
    public:
        UseCommand(Character*);
        void run();
    private:
        Character* player;
};

#endif //DESPLAZACOMANDO_H
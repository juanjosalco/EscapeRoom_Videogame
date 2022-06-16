#ifndef EXIT_H
#define EXIT_H
#include "Command.h"
#include "Character.h"
class ExitCommand:public Command{
    public:
        ExitCommand(Character*);
        void run();
    private:
        Character* Invent;
};


#endif //EXIT_H
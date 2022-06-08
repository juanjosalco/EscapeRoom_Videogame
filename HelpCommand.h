#ifndef HELPCOMMAND_H
#define HELPCOMMAND_H
#include "Command.h"
#include "WordList.h"
class HelpCommand:public Command{
    public:
        HelpCommand(WordList*);
        void run();
    private:
        WordList* avalible;
};


#endif //HELPCOMMAND_H
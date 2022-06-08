#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include "WordList.h"

class Parser {
    public:
        Parser();
        Parser(WordList*);
        WordList* getComands();
        Command* generateCommand();
    private:
        WordList* comands;
};

#endif //PARSER_H
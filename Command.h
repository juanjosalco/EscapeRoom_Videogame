#ifndef COMMAND_H
#define COMMAND_H
#include <iostream>

class Command{
    public:
        Command();
        Command(std::string, std::string);
        std::string getCommand() const;
        std::string getNextWord() const;
        void setNextWord(std::string);
        bool unknown();
        bool hasNextWord();
        virtual void run() = 0;
    private:
        std::string command;
        std::string nextWord;
};

#endif //COMANDO_H
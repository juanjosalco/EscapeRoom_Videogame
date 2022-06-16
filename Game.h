#ifndef GAME_H
#define GAME_H
#include <iostream>

#include "Zone.h"
#include "Note.h"
#include "Piece.h"
#include "MoveToCommand.h"
#include "HelpCommand.h"
#include "TakeCommand.h"
#include "Parser.h"
#include "UseCommand.h"
#include "InventoryCommand.h"
#include "ExitCommand.h"

class Game {
    public:
        Game();
        void creaElementos();
        void creaComandos();
        void setZones();
        void play();
        bool procesaComando(Command*);
        void imprimeBienvenida();
    private:
        Parser parser;
        Character* personaje;
        Zone *start,*chest, *bookcase, *table, *desk, *clocks, *zexit;
        Item *note1, *note2, *note3, *note4, *note5, *note6, *note7, *note8; 
        Item *piece1, *piece2, *piece3, *piece4, *piece5, *piece6;
};
#endif //GAME_H
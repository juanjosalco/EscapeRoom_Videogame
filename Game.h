#ifndef GAME_H
#define GAME_H
#include <iostream>

#include "Zone.h"
#include "MoveToCommand.h"
#include "HelpCommand.h"
#include "TakeCommand.h"
#include "Parser.h"

class Game {
    public:
        Game();
        void creaElementos();
        void creaComandos();
        void play();
        bool procesaComando(Command*);
        void imprimeBienvenida();
    private:
        Parser parser;
        Character* personaje;
        Zone *sala, *comedor, *jardin;
        Item *pocion, *libro, *monedas, *llave; 
};

Game::Game(){
    creaElementos();
    creaComandos();
}

void Game::creaComandos(){
    WordList* comandos=parser.getComands();
    comandos->addCommand("desplaza", new MoveToCommand(personaje));
    comandos->addCommand("toma", new TakeCommand(personaje));
    comandos->addCommand("ayuda", new HelpCommand(comandos));
}

/*crea todos los elementos que están presentes en el juego 
y los configura (cuartos sus zones y que objetos hay en cada room)*/
void Game::creaElementos(){
    personaje=new Character("Fabi asustada");
    sala=new Zone("Sala de la casa, totalmente amueblada");
    comedor=new Zone("Comedor con mesa para 8 personas");
    jardin=new Zone("Jardin!!! Estas fuera de la casa");
    pocion=new Item("note1", "Description");
    libro=new Item("note1", "Description");
    monedas=new Item("note1", "Description");
    llave=new Item("note1", "Description");
    personaje->setPosition(sala);
    sala->addItem(libro);
    sala->addItem(monedas);
    comedor->addItem(pocion);
    comedor->addItem(llave);
}

void Game::imprimeBienvenida(){
    std::cout<<"Acabas de despertar, pero oh sorpresa, estas en una casa siniestra"<<std::endl;
    std::cout <<"La casa se ve oscura, da escalofrios, debes salir de aqui..."<<std::endl;
    std::cout << "Si necesitas ayuda teclea la palabra: ayuda" << std::endl;
}

 void Game::play()
    {
        imprimeBienvenida();
        bool finished = false;
        while (!finished) {
            Command* command = parser.generateCommand();
            finished = procesaComando(command);
        }
        
        std::cout << "Gracias por jugar este juego de aventura" << std::endl;
    }

    bool Game::procesaComando(Command* instr){
        bool salio = false;
        instr->run(); // se esta ejecutando polimorfismo
           
        if(personaje->getPosition()==jardin){
            if(personaje->searchItem("Llave")){
                salio = true;
            }
            else{
                personaje->setPosition(comedor);
            }
        }
     return salio;
    }





#endif //GAME_H
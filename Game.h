#ifndef GAME_H
#define GAME_H
#include <iostream>

#include "Zone.h"
#include "DesplazaComando.h"
#include "AyudaComando.h"
#include "TomaComando.h"
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
    ListaPalabras* comandos=parser.getComandos();
    comandos->agregaComando("desplaza", new DesplazaComando(personaje));
    comandos->agregaComando("toma", new TakeCommand(personaje));
    comandos->agregaComando("ayuda", new HelpCommand(comandos));
}

/*crea todos los elementos que están presentes en el juego 
y los configura (cuartos sus zones y que objetos hay en cada room)*/
void Game::creaElementos(){
    personaje=new Character("Fabi asustada", 150);
    sala=new Zone("Sala de la casa, totalmente amueblada", false);
    comedor=new Zone("Comedor con mesa para 8 personas", false);
    jardin=new Zone("Jardin!!! Estas fuera de la casa", true);
    pocion=new Item("pocion", 50);
    libro=new Item("libro", 15);
    monedas=new Item("Oro", 100);
    llave=new Item("Llave", 0);
    personaje->setPosicion(sala);
    sala->agregaItem(libro);
    sala->agregaItem(monedas);
    comedor->agregaItem(pocion);
    comedor->agregaItem(llave);
    sala->setSalidas(comedor, nullptr, nullptr, nullptr);
    comedor->setSalidas(nullptr, sala, jardin, nullptr);
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
            Command* command = parser.generaComando();
            finished = procesaComando(command);
        }
        
        std::cout << "Gracias por jugar este juego de aventura" << std::endl;
    }

    bool Game::procesaComando(Command* instr){
        bool salio = false;
        instr->run(); // se esta ejecutando polimorfismo
           
        if(personaje->getPosicion()==jardin){
            if(personaje->buscaItem("Llave")){
                salio = true;
            }
            else{
                personaje->setPosicion(comedor);
            }
        }
     return salio;
    }





#endif //GAME_H
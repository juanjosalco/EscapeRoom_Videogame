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
        Zone *chest, *bookcase, *table, *desk, *clocks;
        Item *note1, *note2, *note3, *note4, *note5, *note6, *note7, *note8; 
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
    chest=new Zone("Un viejo baul con un candado");
    bookcase=new Zone("Un librero desgastado con 5 libros");
    table=new Zone("Ub comedor antiguo con 3 velas apagadas en el centro");
    desk=new Zone("Un escritorio con una computadora apagada");
    clocks=new Zone("Un reloj de pendulo al que le falta una aguja");
    note1=new Note("Nota inicial","Una carta escrita a mano", "Bienvenido… Tal vez te preguntes que haces aquí… \nTendrás que averiguarlo por ti mismo, este cuarto contiene las respuestas que buscas y la manera de salir de aquí.\nPD:  Espero que no tardes demasiado o tendré qué sacar otro cadaver de esa habitación. ");
    note2=new Note("Nota Baul","Una ficha de texto", "Si usaste la llave para intentar abrir la puerta me decepcionas, ¿De verdad pensaste que sería tan fácil?. \nSi viniste directo al baúl, que suerte tienes. \nDe seguro ya te habrás preguntado quien soy y porqué hago esto, de lo primero puedo decirte que soy alguien que conoces pero del porque… \n\nEs algo que deberás averiguar.");
    note3=new Note("Nota librero","Una hoja de recortes", "Parece que no has olvidado lo que aprendiste en la escuela, aunque tal vez a mí sí. \nY si así fue, también olvidaste lo que me hiciste, espero que antes de que terminemos aquí lo recuerdes.\nPD: Justo al terminar este día pero también al inicio del mañana podrás encontrar más respuestas");
    note4=new Note("Nota reloj","Una placa con una inscripcion", "¿El tiempo vuela cuando te diviertes cierto? ¿O solo soy yo?, cómo sea… \nQué tantos privilegios tenías que no te dabas cuenta de que eran privilegios. \nEspero recuerdes a aquellos que no tenemos ni uno de ellos.\nPD: Parece que no eres tan tonto como recordaba, tu siempre estuviste bajo los reflectores \ny yo en tu sombra ojalá aún tengas ese brillo abrasador porque lo necesitarás.");
    note5=new Note("Nota Mesa","Un mensaje el techo escrito en sangre","Que raro tu mirando hacia arriba, siendo que siempre nos miraste hacia abajo, por cierto, ¿Te gustaron mis velas mágicas? \nFueron un favor de un gran amigo, dime… ¿Alguna vez has hecho favores? \nPD:  Espero recuerdes mantenerte conectado con las personas que amas, no queremos que se pierdan de tus memes…");
    note6=new Note("Nota escritorio","Un mensaje en la computadora","De seguro tienes frío, pero tranquilo es algo temporal, ya sea que termines con él o él contigo. \nTodo depende de ti, de todas formas, creo que has terminado por hoy, la contraseña del cajón de abajo a la derecha es 2629, \nábrela, toma la llave y lárgate de aquí.. Si puedes…");
    note7=new Note("Nota final","Unar carta hecha a mano", "Bienvenido al final, o al comienzo ya que todo final siempre es el comienzo de algo mejor. \nAsí que espero que de ahora en adelante seas mejor con las personas que te rodean, y espero que tu corazón ya no sea tan frío como las gotas de lluvia que caían sobre mi rostro aquella noche \npor no poder irme en camión…¡¡¡ DEBISTE PRESTARME ESOS 5 PESOOOOOOOS !!! Era tu mejor amigo… Solo te pedí ayuda… Y que hiciste? \nPD: Tranquilo… Si piensas en buscarme saliendo de aquí, no lo intentes, ya estaré muerto o tal vez tu lo estés \n\n**Escuchas un ruido detrás de ti, cuando volteas…**");
    note8=new Note("Nota final","Unar carta hecha a mano", "* Despiertas de nuevo en la cama del hospital, al parecer fue demasiado estrés por semana 5 \nescuchas a tu familia y amigos alegrarse porque abriste los ojos… \nPero también lo escuchas a él decir…");

    personaje->setPosition(chest);
    chest->addItem(note2);
    chest->addItem(note3);
    bookcase->addItem(note1);
    bookcase->addItem(note4);
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
           
        if(personaje->getPosition()==table){
            if(personaje->searchItem("Llave")){
                salio = true;
            }
            else{
                personaje->setPosition(bookcase);
            }
        }
     return salio;
    }





#endif //GAME_H
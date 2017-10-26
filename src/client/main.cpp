#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML

#include "state.h"
//#include "state/TestState.h"
#include "state/Texture.h"


using namespace std;
using namespace state;

int main(int argc,char* argv[]) {
    //Tests unitaires avec différents modes
    if (argc < 2 ){
        cout << "Usage:  ./bin/client <mode>" << endl;
        cout << "Modes disponibles: " << endl;
        cout << "   hello: affiche un simple message dans la console" << endl;
        cout << "   state: effectue des opérations élémentaires sur l'état" << endl;
        cout << "   render: affiche un état" << endl;
        //cout << "   engine: teste le moteur de jeu" << endl;
        //cout << "   random_ai: teste l'IA aléatoire" << endl;
        //cout << "   heuristic_ai: teste l'IA heuristique" << endl;
        //cout << "   rollback: teste le retour en arrière" << endl;
        //cout << "   deep_ai: teste l'IA avancée" << endl;
        //cout << "   replay: affiche un enregistrement" << endl;
        //cout << "   thread: teste l'exécution du moteur dans un thread" << endl;
        //cout << "   network [<url serveur>] [<port>]: teste le jeu en mode réseau" << endl;

        return 2;
    }//nombre argument ici bin/client represente un argument et hello un autre par exemple
    
    string mode = argv[1];
    if (mode == "hello")
        cout << "Hello world !" << endl; //endl pour passer à la ligne
    
    else if (mode == "state"){
        //testState();
        
        cout << "Tests état..." << endl;
        cout << "Fabrique un état..." << endl;
        State etat;
        //etat.getChars().resize(6,1);
        
        //Tests sur la liste des personnages
        cout << "Tests sur la liste des personnages..." << endl;
        cout << "Vérifie que la largeur est nulle:    ";
        if(etat.getChars().getWidth() == 0)
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        
        
        cout << "Ajoute un colon..." << endl;
        Colon luigi;
        /*etat.getChars().add(*luigi);
        
        cout << "Vérifie que la largeur est 1:    ";
        if(etat.getChars().getWidth() == 1)
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        cout << "Vérifie que le premier élément est non nul:    ";
        if(etat.getChars().get(1,1) != 0)
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        cout << "Vérifie que le premier élément est bien un colon:    ";
        if(etat.getChars().get(1,1)->getTypeId() == 1)
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        cout << "Vérifie que le premier élément est statique:    ";
        if(etat.getChars().get(1,1)->isStatic() == true)
            cout << "OK" << endl;
        else
            cout << "Error" << endl;*/
    }
    
    else if (mode == "render"){
        
        //texturetext();
        // on crée la fenêtre
    sf::RenderWindow window(sf::VideoMode(512, 256), "Tilemap");

    // on définit le niveau à l'aide de numéro de tuiles
    const int level[] =
    {
        0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
        1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
        0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
        0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
        0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
        2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
        0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
    };

    // on crée la tilemap avec le niveau précédemment défini
    TileMap map;
    if (!map.load("res/luigi.png", sf::Vector2u(32, 32), level, 16, 8))
        return -1;

    // on fait tourner la boucle principale
    while (window.isOpen())
    {
        // on gère les évènements
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        // on dessine le niveau
        window.clear();
        window.draw(map);
        window.display();
    }
    }
    
    return 0;
}

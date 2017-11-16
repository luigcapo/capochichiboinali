#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML

#include "state.h"
#include "state/TestState.h"
#include "render.h"
#include "engine/TestEngine.h"
//#include "TestRendu.h"


using namespace std;
using namespace state;
using namespace engine;

int main(int argc,char* argv[]) {
    
    //Menu des tests unitaires avec différents modes
    if (argc < 2 ){
        menu();
        return 2;
    }//nombre argument ici bin/client represente un argument et hello un autre par exemple
    
    string mode = argv[1];
    if (mode == "hello")
        cout << "Hello World !" << endl; //endl pour passer à la ligne
    
    else if (mode == "state")
        testState();
    
    else if (mode == "render"){
      //TestRendu();  
    
    // on crée la fenêtre
    sf::RenderWindow window(sf::VideoMode(1152, 720), "Test sur le rendu");
    
    
    // on crée un état
    state::State etat;
    
    
    // test sur la liste des personnages
    state::Millitary* ep = new state::Millitary(EPEISTE);
    ep->setX(1);
    ep->setY(1);
    ep->setOrientation(state::EAST);
    
    state::Millitary* msq = new state::Millitary(MOUSQUETAIRE);
    msq->setX(3);
    msq->setY(2);
    msq->setOrientation(state::SOUTH);
    
    state::Millitary* mt = new state::Millitary(MITRAILLEUR);
    mt->setX(5);
    mt->setY(3);
    mt->setOrientation(state::NORTH_EAST);
    
    etat.getChars().add(msq);
    etat.getChars().add(mt);
    etat.getChars().add(ep);
    /*etat.getChars().setChar(0, new Millitary(EPEISTE));
    etat.getChars().setChar(1, new Millitary(MOUSQUETAIRE));
    etat.getChars().setChar(2, new Colon());
    etat.getChars().setChar(2, new Catapult());
    //etat.getChars().set(2, 4, new Millitary(EPEISTE));
    //etat.getChars().set(3, 1, new Millitary(MOUSQUETAIRE));
    //tat.getChars().set(1, 2, new Catapult());*/
    
    render::ElementTabLayer tChars(etat.getChars());
    tChars.initSurface();
    
    
    
    // test sur la grille
    etat.getGrid().resize(5,5);
    etat.getGrid().set(0, 0, new Plateau(PLAINE));
    etat.getGrid().set(0, 1, new Plateau(PLAINE));
    etat.getGrid().set(0, 2, new Plateau(PLAINE));
    etat.getGrid().set(0, 3, new Plateau(PLAINE));
    etat.getGrid().set(0, 4, new Plateau(PLAINE));
    etat.getGrid().set(1, 0, new Plateau(PLAINE));
    etat.getGrid().set(1, 1, new Plateau(PLAINE));
    etat.getGrid().set(1, 2, new Plateau(DESERT));
    etat.getGrid().set(1, 3, new Plateau(DESERT));
    etat.getGrid().set(1, 4, new Plateau(PLAINE));
    etat.getGrid().set(2, 0, new Plateau(PLAINE));
    etat.getGrid().set(2, 1, new Plateau(PLAINE));
    etat.getGrid().set(2, 2, new Plateau(DESERT));
    etat.getGrid().set(2, 3, new Plateau(DESERT));
    etat.getGrid().set(2, 4, new Plateau(PLAINE));
    etat.getGrid().set(3, 0, new Plateau(PLAINE));
    etat.getGrid().set(3, 1, new Plateau(PLAINE));
    etat.getGrid().set(3, 2, new Plateau(PLAINE));
    etat.getGrid().set(3, 3, new Plateau(PLAINE));
    etat.getGrid().set(3, 4, new Plateau(PLAINE));
    etat.getGrid().set(4, 0, new Plateau(PLAINE));
    etat.getGrid().set(4, 1, new Plateau(PLAINE));
    etat.getGrid().set(4, 2, new Plateau(PLAINE));
    etat.getGrid().set(4, 3, new Plateau(PLAINE));
    etat.getGrid().set(4, 4, new Plateau(PLAINE));

    render::ElementTabLayer tGrid(etat.getGrid());
    tGrid.initSurface();
    
    
    
    
    // Map2
    state::ElementTab map2(4,4);
    map2.setMap2();
    map2.set(0,0, new Plateau(PLAINE));
    map2.set(0,1, new Plateau(PLAINE));
    map2.set(0,2, new Plateau(PLAINE));
    map2.set(0,3, new Plateau(PLAINE));
    map2.set(1,0, new Plateau(PLAINE));
    map2.set(1,1, new Plateau(PLAINE));
    map2.set(1,2, new Plateau(PLAINE));
    map2.set(1,3, new Plateau(PLAINE));
    map2.set(2,0, new Plateau(PLAINE));
    map2.set(2,1, new Plateau(PLAINE));
    map2.set(2,2, new Plateau(PLAINE));
    map2.set(2,3, new Plateau(PLAINE));
    map2.set(3,0, new Plateau(PLAINE));
    map2.set(3,1, new Plateau(PLAINE));
    map2.set(3,2, new Plateau(PLAINE));
    map2.set(3,3, new Plateau(PLAINE));
    
    render::ElementTabLayer tMap2(map2);
    tMap2.initSurface();
    
    

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
        window.draw(*(tGrid.getSurface()));
        window.draw(*(tMap2.getSurface()));
        window.draw(*(tChars.getSurface()));
        window.display();
    }
    
    
    
    
    
    }
    
    else if (mode == "engine"){
        testEngine();
    }
    
    else if (mode == "random_ai"){
        
    }
    
    else{
        cout << "Mode invalide" << endl;
    }
    
    return 0;
}

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
//#include "TestRendu.h"


using namespace std;
using namespace state;

int main(int argc,char* argv[]) {
    
    //Menu des tests unitaires avec différents modes
    if (argc < 2 ){
        menu();
        return 2;
    }//nombre argument ici bin/client represente un argument et hello un autre par exemple
    
    string mode = argv[1];
    if (mode == "hello")
        cout << "Hello world !" << endl; //endl pour passer à la ligne
    
    else if (mode == "state")
        testState();
    
    else if (mode == "render"){
      //TestRendu();
        
        
        
    /*    
    
    // on crée la fenêtre
    sf::RenderWindow window(sf::VideoMode(528, 256), "Test Liste Personnages");
    
    
    
    
    
    state::State etat;
    state::Colon *c = new Colon();
    etat.getChars().add(c);
    state::Millitary *ep = new Millitary(EPEISTE);
    etat.getChars().add(ep);
    state::Millitary *msq = new Millitary(MOUSQUETAIRE);
    etat.getChars().add(msq);
    state::Catapult *ctp = new Catapult();
    etat.getChars().add(ctp);
    etat.getChars().add(c);
    etat.getChars().add(ep);
    etat.getChars().add(ctp);
    
    render::StateLayer* tstate = new render::StateLayer(etat.getChars());
    tstate->initSurface();
    
    
    
    
    

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
        window.draw(tstate->getSurface());
        window.display();
    }*/
    
    
    
    
    }
    
    else if (mode == "engine"){
        // testEngine();
    }
    
    else if (mode == "random_ai"){
        
    }
    
    else{
        cout << "Choisir un mode" << endl;
        menu();
    }
    
    return 0;
}

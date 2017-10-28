#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML

#include "state.h"
#include "state/TestState.h"
#include "state/Texture.h"


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
        texturetext();
    }
    
    else{
        cout << "Choisir un mode" << endl;
        menu();
    }
    
    return 0;
}

#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML

#include "state.h"
#include "tests/TestState.h"
#include "render.h"
#include "engine/TestEngine.h"
#include "tests/TestRender.h"


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
        //testRender();    // (Test manuel sans load)
        testMap();  // Test avec load(CSV)
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

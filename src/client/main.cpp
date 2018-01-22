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
#include "tests/TestEngine.h"
#include "tests/TestRender.h"
#include "tests/TestAI.h"
#include "tests/TestServer.h"


using namespace std;
using namespace state;
using namespace engine;
using namespace ai;

int main(int argc,char* argv[]) {
    
    //Menu des tests unitaires avec différents modes
    if (argc < 2 ){
        menu();
        return 2;
    }//nombre argument ici bin/client represente un argument et hello un autre par exemple
    
    string mode = argv[1];
    if (mode == "hello"){
        cout << "Hello World !" << endl; //endl pour passer à la ligne
    }
    else if (mode == "state"){
        testState();
    }
    else if (mode == "render"){
        //testRender();    // (Test manuel sans load)
        testMap();  // Test avec load(CSV)
    }
    else if (mode == "engine"){
        testEngine();
    }
    else if (mode == "random_ai"){
        testRandomAI();
    }
    else if (mode == "heuristic_ai"){
        cout << "Mode indisponible" << endl;
    }
    else if (mode == "rollback"){
        testRollback();
    }
    else if (mode == "deep_ai"){
        cout << "Mode indisponible" << endl;
    }
    else if (mode == "record"){
        testJson();
    }
    else if (mode == "play"){
        testReplay();
    }
    else if (mode == "thread"){
        testThread();
    }
    else if (mode == "network41"){
        cout << "Connexion au serveur..." << endl;
        if(argc != 3){
            cout << "Usage: ./bin/client network [port]" << endl;
            return 2;
        }
        int port = atoi(argv[2]);
        //string name = argv[3];
        
        testServer(port);
    }
    else if (mode == "network"){
        cout << "Connexion au serveur..." << endl;
        if(argc != 3){
            cout << "Usage: ./bin/client network [port]" << endl;
            return 2;
        }
        int port = atoi(argv[2]);
        
        testClient(port);
    }
    else{
        cout << "Mode invalide" << endl;
    }
    
    return 0;
}

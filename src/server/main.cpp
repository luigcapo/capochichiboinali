#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne

// Fin test SFML

#include "state.h"
#include "tests/TestState.h"
#include "render.h"
#include "tests/TestEngine.h"
#include "tests/TestRender.h"
#include "tests/TestAI.h"


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
    else if (mode == "record"){
        //testState();
    }

    else{
        cout << "Mode invalide" << endl;
    }
    
    return 0;
}

#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML

#include "state.h"

using namespace std;
using namespace state;

int main(int argc,char* argv[]) 
{
    
    if (argc < 2 ){
        cout << "Usage: ";
        return 2;
    }//nombre argument ici bin/client represente un argument et hello un autre par exemple
    
    string mode =argv[1];
    if (mode=="hello"){
        cout <<"Hello world !" <<endl; //endl pour passer à la ligne.
    }
    else if (mode == "state"){
        Millitary m;
        m = new Millitary(1);
       
        cout<< m->getTypeId() <<endl;
        delete m;
    }
       
    //cout << "It works !" << endl;

    return 0;
}

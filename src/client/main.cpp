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
        cout << "Test implantation des états..." << endl;  
        cout << "Création d'un épéiste !" << endl;
        Millitary m(1);
        cout << "Vérifie si c'est bien un militaire: ";
        if(m.getTypeId()==1) cout << "OK" << endl;
        else cout << "Erreur" << endl;
    }
       
    //cout << "It works !" << endl;

    return 0;
}

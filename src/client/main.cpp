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
    //Tests unitaires à faire sur un autre fichier
    if (argc < 2 ){
        cout << "Usage: ./bin/client <mode>" << endl;
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
    if (mode == "hello"){
        cout << "Hello world !" << endl; //endl pour passer à la ligne.
    }
    else if (mode == "state"){
        cout << "Test implantation des états..." << endl; 
        cout << "Fabrique un état..." << endl;
        cout << "Création d'une colonie..." << endl;
        //Colonie c;
        cout << "Vérifie si c'est bien statique: ";
        //if(c.isStatic()==true) cout << "OK" << endl;
        //else cout << "Erreur" << endl;*/
        //...etc
    }
    
    return 0;
}

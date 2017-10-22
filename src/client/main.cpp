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
        cout << "Test de l'implantation des états..." << endl; 
        cout << "Fabrique un état..." << endl;
        
        cout << "Tests sur la liste des personnages..." << endl;
        cout << "Ajout d'un colon..." << endl;
        cout << "Vérifie que la largeur est 1:    ";
        cout << "Vérifie que le premier élément est non nul:    ";
        cout << "Vérifie que le premier élément est bien un colon:    ";
        cout << "Vérifie que le premier élément est statique:    ";
        cout << "Ajout d'un militaire de type épéiste..." << endl;
        cout << "Vérifie que la largeur est 2:    ";
        cout << "Vérifie que le deuxième élément est non nul:    ";
        cout << "Vérifie que le deuxième élément est bien un militaire:    ";
        cout << "Vérifie que le militaire est du bon type:    ";
        cout << "Ajout d'un militaire de type mousquetaire..." << endl;
        cout << "Vérifie que la largeur est 3:    ";
        cout << "Vérifie que le troisième élément est non nul:    ";
        cout << "Vérifie que le troisième élément est bien un militaire:    ";
        cout << "Vérifie que le militaire est du bon type:    ";
        cout << "Ajout d'une catapulte..." << endl;
        cout << "Vérifie que la largeur est 4:    ";
        cout << "Vérifie que le quatrième élément est non nul:    ";
        cout << "Vérifie que le quatrième élément est bien une catapulte:    ";
        
        cout << "Tests sur la grille..." << endl;
        cout << "Cree une grille de taille 11 par 10..." << endl;
        cout << "Vérifie que la largeur est correte:    ";
        cout << "Vérifie que la hauteur est correte:    ";
        cout<<
        cout << "Vérifie que la largeur est correte:    ";
        cout << "Vérifie que la largeur est correte:    ";
        cout << "Vérifie que la largeur est correte:    ";
        cout << "Vérifie que la largeur est correte:    ";
        cout << "Vérifie que la largeur est correte:    ";
        cout << "Vérifie que la largeur est correte:    ";
        cout << "Vérifie que la largeur est correte:    ";
        cout << "Vérifie que la largeur est correte:    ";
    }
    
    return 0;
}

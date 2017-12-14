

#include "TestState.h"

namespace state{
    
    void menu(){
        cout << "Usage:  ./bin/client <mode>" << endl;
        cout << "Modes disponibles: " << endl;
        cout << "   hello: affiche un simple message dans la console" << endl;
        cout << "   state: effectue des opérations élémentaires sur l'état" << endl;
        cout << "   render: affiche un état" << endl;
        cout << "   engine: teste le moteur de jeu" << endl;
        cout << "   random_ai: teste l'IA aléatoire" << endl;
        cout << "   heuristic_ai: teste l'IA heuristique" << endl;
        cout << "   rollback: teste le retour en arrière" << endl;
        cout << "   deep_ai: teste l'IA avancée" << endl;
        cout << "   record: réaliser un enregistrement" << endl;
        cout << "   play: affiche un enregistrement" << endl;
        cout << "   thread: teste l'exécution du moteur dans un thread" << endl;
        //cout << "   network [<url serveur>] [<port>]: teste le jeu en mode réseau" << endl;
    }
    
    void testState(){
        cout << "Tests état..." << endl;
        cout << "Fabrique un état..." << endl;
        State etat;
        
        //Tests sur la liste des personnages
        cout << "Tests sur la liste des personnages..." << endl;
        cout << "Vérifie que la largeur est nulle:    ";
        if(etat.getChars().size() == 0)
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        
        //Colon
        cout << "Ajoute un colon..." << endl;
        etat.getChars().add(new Colon());
        
        cout << "Vérifie que la largeur est 1:    ";
        if(etat.getChars().size() == 1)
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        cout << "Vérifie que le premier élément est non nul:    ";
        if(etat.getChars().get(0,0) != 0)   // 0,1
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        cout << "Vérifie que le premier élément est bien un colon:    ";
        if(etat.getChars().get(0,0)->getTypeId() == 1)
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        /*
         * A modifier et tester
         * 
         * cout << "Vérifie que le premier élément est statique:    ";
         * if(etat.getChars().get(0,1)->isStatic())
            *cout << "OK" << endl;
         *else
            *cout << "Error" << endl;
         * 
         * */
        
        
        //delete c;
        /*
         * Rajouter destructeur dans ElementTab car supprimer c conduit à une erreur de segmentation
         * 
         * 
         */
        
        
        //Millitary
        cout << "Ajout d'un militaire de type épéiste..." << endl;
        etat.getChars().add(new Military(EPEISTE));
        
        cout << "Vérifie que la largeur est 2:    ";
        if(etat.getChars().size() == 2)
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
       
        cout << "Vérifie que le deuxième élément est non nul:    ";
        if(etat.getChars().get(1,0) != 0)   // (1,1)
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        cout << "Vérifie que le deuxième élément est bien un militaire:    ";
        if(etat.getChars().get(1,0)->getTypeId() == MILITARY)
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        cout << "Vérifie que le militaire est du bon type:    ";
        /*
         * 
         * A tester à partir de la liste de personnages
         * 
         * 
         * */
        /*if(ep->getMilTypeId() == 1)
            cout << "OK" << endl;
        else
            cout << "Error" << endl;*/
        
        //delete ep;
        
        //Millitary
        cout << "Ajout d'un militaire de type mousquetaire..." << endl;
        Military *msq = new Military(MOUSQUETAIRE);
        etat.getChars().add(msq);
        
        cout << "Vérifie que la largeur est 3:    ";
        if(etat.getChars().size() == 3)
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        cout << "Vérifie que le troisième élément est non nul:    ";
        if(etat.getChars().get(2,0) != 0)   // 2,1
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        cout << "Vérifie que le troisième élément est bien un militaire:    ";
        if(etat.getChars().get(2,0)->getTypeId() == MILITARY)
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        cout << "Vérifie que le militaire est du bon type:    ";
        if(msq->getMilTypeId() == 3)
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        //delete msq;
        
        //Catapulte
        /*cout << "Ajout d'une catapulte..." << endl;
        Catapult *ctp = new Catapult();
        etat.getChars().add(ctp);
        
        cout << "Vérifie que la largeur est 4:    ";
        if(etat.getChars().size() == 4)
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        cout << "Vérifie que le quatrième élément est non nul:    ";
        if(etat.getChars().get(3,1) != 0)
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        cout << "Vérifie que le quatrième élément est bien une catapulte:    ";
        if(etat.getChars().get(3,1)->getTypeId() == 3)
            cout << "OK" << endl;
        else{
            cout << "Error" << endl;
        }*/
        //delete ctp;
        
        
        
        
        
        //Tests sur la grille
        cout << "Tests sur la grille..." << endl;
        cout << "redimensionne en 15 par 12..." << endl;
        etat.getGrid().resize(15,12);
        
        cout << "Vérifie que la largeur est correte:    ";
        if(etat.getGrid().getWidth() == 15)
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        cout << "Vérifie que la hauteur est correte:    ";
        if(etat.getGrid().getHeight() == 12)
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        
        cout << "Vérifie que toutes les cases sont nulles:    ";
        bool result = true;
        for(std::size_t i = 0; i < etat.getGrid().getWidth(); i++){
            for(std::size_t j=0; j < etat.getGrid().getHeight(); j++){
                if(etat.getGrid().get(i, j) == nullptr)
                    result = result & true;
                else
                    result = result & false;
            }
        }
        if(result == true)
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        


       cout << "Rempli avec des terrains de type plaine..." << endl;
        for(std::size_t i = 0; i < etat.getGrid().getWidth(); i++){
            for(std::size_t j=0; j < etat.getGrid().getHeight(); j++){
                etat.getGrid().set(i, j, new Terrain(PLAINE));
            }
        }
          
        
        cout << "Vérifie que toutes les cases sont des terrains de type plaine:    ";
        result = true;
        for(std::size_t i = 0; i < etat.getGrid().getWidth(); i++){
            for(std::size_t j=0; j < etat.getGrid().getHeight(); j++){
                if(etat.getGrid().get(i, j)->getTypeId() == TERRAIN){
                    Terrain *t = (Terrain*)etat.getGrid().get(i, j);
                    if(t->getTerrainTypeId() == PLAINE)
                        result = result & true;
                    else
                        result = result & false;
                }
                else
                    result = result & false;
            }
        }
        if(result == true)
            cout << "OK" << endl;
        else
            cout << "Error" << endl;

        
        //Terrain
        cout << "Ajoute un terrain en 10,8 de type DESERT... " << endl;
        Terrain *pltd = new Terrain(DESERT);
        etat.getGrid().set(10, 8, pltd);
        
        cout << "Vérifie que la cellule modifiée est bien un terrain:    ";
        if(etat.getGrid().get(10, 8)->getTypeId() == TERRAIN)
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        cout << "Vérifie que le terrain est du bon type:    ";
        if(pltd->getTerrainTypeId() == DESERT)
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        
        //Ressource
        cout << "Ajoute une ressource en 1,5 de type 3..." << endl;
        Ressource *rsc = new Ressource(CHARBON);
        etat.getGrid().set(1, 5, rsc);
        
        cout << "Vérifie que la cellule modifiée est bien une ressource:    ";
        if(etat.getGrid().get(1, 5)->getTypeId() == RESSOURCE)
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        cout << "Vérifie que la ressource est du bon type:    ";
        if(rsc->getRessourceTypeId() == CHARBON)
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        
        //Batiment
        cout << "Ajoute une batiment en 6,10..." << endl;
        Batiment* bln = new Batiment(BARRACK);
        etat.getGrid().set(6, 10, bln);
        
        cout << "Vérifie que la cellule modifiée est bien un batiment:    ";
        if(etat.getGrid().get(6, 10)->getTypeId() == BATIMENT)
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
    }   // TestState
    
    
    
}
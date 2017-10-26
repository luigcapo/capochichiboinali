/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "TestState.h"

namespace state{
    
    void testState(){
        cout << "Tests état..." << endl;
        cout << "Fabrique un état..." << endl;
        //State etat;
        //etat.getChars().resize(6,1);
        
        //Tests sur la liste des personnages
        cout << "Tests sur la liste des personnages..." << endl;
        /*cout << "Vérifie que la largeur est nulle:    ";
        if(etat.getChars().getWidth() == 0)
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        
        
        cout << "Ajoute un colon..." << endl;
        Colon c;
        etat.getChars().add(c);
        
        cout << "Vérifie que la largeur est 1:    ";
        if(etat.getChars().getWidth() == 1)
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        cout << "Vérifie que le premier élément est non nul:    ";
        if(etat.getChars().get(1,1) != 0)
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        cout << "Vérifie que le premier élément est bien un colon:    ";
        if(etat.getChars().get(1,1)->getTypeId() == 1)
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        cout << "Vérifie que le premier élément est statique:    ";
        if(etat.getChars().get(1,1)->isStatic() == true)
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        
        
        cout << "Ajout d'un militaire de type épéiste..." << endl;
        Millitary ep(1);
        etat.getChars().add(ep);
        
        cout << "Vérifie que la largeur est 2:    ";
        if(etat.getChars().getWidth() == 2)
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
       
        cout << "Vérifie que le deuxième élément est non nul:    ";
        if(etat.getChars().get(2,1) != 0)
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        cout << "Vérifie que le deuxième élément est bien un militaire:    ";
        if(etat.getChars().get(2,1)->getTypeId() == 2)
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        cout << "Vérifie que le militaire est du bon type:    ";
        if(ep.getMillTypeID() == 1)
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        
        
        cout << "Ajout d'un militaire de type mousquetaire..." << endl;
        Millitary msq(3);
        etat.getChars().add(msq);
        
        cout << "Vérifie que la largeur est 3:    ";
        if(etat.getChars().getWidth() == 3)
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        cout << "Vérifie que le troisième élément est non nul:    ";
        if(etat.getChars().get(3,1) != 0)
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        cout << "Vérifie que le troisième élément est bien un militaire:    ";
        if(etat.getChars().get(3,1)->getTypeId() == 2)
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        cout << "Vérifie que le militaire est du bon type:    ";
        if(msq.getMillTypeID() == 3)
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        
        
        cout << "Ajout d'une catapulte..." << endl;
        Catapult ctp;
        etat.getChars().add(ctp);
        
        cout << "Vérifie que la largeur est 4:    ";
        if(etat.getChars().getWidth() == 4)
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        cout << "Vérifie que le quatrième élément est non nul:    ";
        if(etat.getChars().get(4,1) != 0)
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        cout << "Vérifie que le quatrième élément est bien une catapulte:    ";
        if(etat.getChars().get(4,1)->getTypeId() == 3)
            cout << "OK" << endl;
        else{
            cout << "Error" << endl;
        }
        
        
        
        
        
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
        for(int i = 0; i < etat.getGrid().getWidth(); i++){
            for(int j=0; j < etat.getGrid().getHeight(); i++){
                if(etat.getGrid().get(i, j) == 0)
                    cout << "OK" << endl;
                else
                    cout << "Error" << endl;
            }
        }
        
        cout << "Rempli avec des plateaux vides...";
        Plateau plte(1);
        for(int i = 0; i < etat.getGrid().getWidth(); i++){
            for(int j=0; j < etat.getGrid().getHeight(); i++){
                etat.getGrid().set(i, j, plte);
            }
        }
        
        cout << "Vérifie que toutes les cases sont des espaces vides:    ";
        for(int i = 0; i < etat.getGrid().getWidth(); i++){
            for(int j=0; j < etat.getGrid().getHeight(); i++){
                if(etat.getGrid().get(i, j)->getTypeId() == 5)  //A vérifier
                    cout << "OK" << endl;
                else
                    cout << "Error" << endl;
            }
        }
        
        
        
        cout << "Ajoute un mur en 5,9 de type 1..." << endl;
        Wall m(1);
        etat.getGrid().set(5, 9, m);
        
        cout << "Vérifie que la cellule modifiée est bien un mur:    ";
        if(etat.getGrid().get(5, 9)->getTypeId() == 4)
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        cout << "Vérifie que le mur est du bon type:    ";
        if(m.getWallTypeId() == 1)
            cout << "OK" << endl;
        else
            cout << "Error" << endl;  
        
        
        
        cout << "Ajoute un mur en 14,2 de type 2..." << endl;
        Wall m1(2);
        etat.getGrid().set(14, 2, m1);
        
        cout << "Vérifie que la cellule modifiée est bien un mur:    ";
        if(etat.getGrid().get(14, 2)->getTypeId() == 4)
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        cout << "Vérifie que le mur est du bon type:    ";
        if(m1.getWallTypeId() == 2)
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        
        
        cout << "Ajoute un plateau en 10,8 de type 4... " << endl;
        Plateau pltd(4);
        etat.getGrid().set(10, 8, pltd);
        
        cout << "Vérifie que la cellule modifiée est bien un plateau:    ";
        if(etat.getGrid().get(10, 8)->getTypeId() == 5)
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        cout << "Vérifie que le plateau est du bon type:    ";
        if(pltd.getPlateautypeId() == 4)
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        
        
        cout << "Ajoute une ressource en 1,5 de type 3..." << endl;
        Ressource rsc(3);
        etat.getGrid().set(1, 5, rsc);
        
        cout << "Vérifie que la cellule modifiée est bien une ressource:    ";
        if(etat.getGrid().get(1, 5)->getTypeId() == 6)
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        cout << "Vérifie que la ressource est du bon type:    ";
        if(rsc.getRessourceTypeId() == 3)
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        
        
        cout << "Ajoute une colonie en 6,10..." << endl;
        Colonie cln;
        etat.getGrid().set(6, 10, cln);
        
        cout << "Vérifie que la cellule modifiée est bien une colonie:    ";
        if(etat.getGrid().get(1, 5)->getTypeId() == 7)
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        */
        
        //Tests classe Batiment
    }
}
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
        /*State etat;
        //etat.getChars().resize(6,1);
        
        //Tests sur la liste des personnages
        cout << "Tests sur la liste des personnages..." << endl;
        cout << "Vérifie que la largeur est nulle:    ";
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
        if()
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        cout << "Rempli avec des espaces vides...";
        if()
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        cout << "Vérifie que toutes les cases sont des espaces vides:    ";
        if()
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        cout << "Ajoute un mur en 14,9 de type 1..." << endl;
        cout << "Vérifie que la cellule modifiée est bien un mur:    ";
        if()
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        cout << "Vérifie que le mur est du bon type:    ";
        if()
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        cout << "Ajoute un mur en 7,8 de type 2..." << endl;
        cout << "Vérifie que la cellule modifiée est bien un mur:    ";
        if()
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        cout << "Vérifie que le mur est du bon type:    ";
        if()
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        cout << "Ajoute un plateau en 10,8 de type 4... " << endl;
        cout << "Vérifie que la cellule modifiée est bien un plateau:    ";
        if()
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        cout << "Vérifie que le plateau est du bon type:    ";
        if()
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        cout << "Ajoute une ressource en 1,5 de type 3..." << endl;
        cout << "Vérifie que la cellule modifiée est bien une ressource:    ";
        if()
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        cout << "Vérifie que la ressource est du bon type:    ";
        if()
            cout << "OK" << endl;
        else
            cout << "Error" << endl;
        
        cout << "Ajoute une colonie en 6,10..." << endl;
        cout << "Vérifie que la cellule modifiée est bien une colonie:    ";
        if()
            cout << "OK" << endl;
        else
            cout << "Error" << endl;*/
        
        //Tests classe Batiment
    }
}
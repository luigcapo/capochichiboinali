/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "TestEngine.h"
using namespace state;

namespace engine{
    void testEngine(){
        std::cout<< "Epoque"<<std::endl;
        State state;
        std::cout<< "Ajout de deux joueurs à notre état"<<std::endl;
        state.addJoueur(new Joueur(1));
        state.addJoueur(new Joueur(2));
        //ElementTab tabl=ElementTab();
        //tabl = state.getChars();
        std::cout<<"ajout d'élément mobile à notre state"<<std::endl;
        Millitary *m=new Millitary(MOUSQUETAIRE);
        Millitary *m1=new Millitary(EPEISTE);
        Colon *c = new Colon();
        Millitary *m2= new Millitary(MOUSQUETAIRE);
        m->setJ(1);
        m1->setJ(1);
        m1->setCombat(30);
        m2->setJ(2);
        c->setJ(1);
        state.getChars().resize(20,20);
        state.getChars().set(3,5,m);
        state.getChars().set(4,4,m1);
        state.getChars().set(5,4,c);
        state.getChars().set(5,5,m2);
        std::cout<<"crée le moteur à partir de l'état"<<std::endl;
        Engine*eng = new Engine(state);
        /*std::cout<<"ajoute de nouvelle commande"<< std::endl;
        eng->execute(new MoveCommand(3,5,4,4));
        std::cout<<"ajoute de nouvelle commande"<< std::endl;
        eng->execute(new MoveCommand(4,4,5,5));
        std::cout<<"ajoute de nouvelle commande"<< std::endl;*/
        
        eng->execute(new AttaqueCommand(4,4,5,5));
        std::cout<< m2->getPv() <<std::endl;
        /*std::cout<<"ajoute de nouvelle commande"<< std::endl;
        eng->resize(10);
        eng->update();*/
        std::cout<<"ajoute de nouvelle commande"<< std::endl;
        std::cout<< m2->getPv() <<std::endl;
        std::cout<< state.getChars().get(4,4)->getTypeId() <<std::endl;
       
    }

    
    
}

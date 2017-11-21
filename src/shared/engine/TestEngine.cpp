/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "TestEngine.h"
#include "state/Batiment.h"
using namespace state;

namespace engine{
    void testEngine(){
        std::cout<< "Epoque 1"<<std::endl;
        State state;
        std::cout<< "Ajout de deux joueurs à notre état"<<std::endl;
        state.addJoueur(new Joueur(1));
        state.addJoueur(new Joueur(2));
        std::cout<<"ajout des éléments à notre état"<<std::endl;
        state.getChars().resize(100,100);
        Millitary *m=new Millitary(MOUSQUETAIRE);
        Millitary *m1=new Millitary(EPEISTE);
        Colon *c = new Colon();
        Millitary *m2= new Millitary(MOUSQUETAIRE);
        Batiment *b=new Batiment(WATER_MILL);
        Batiment *bb=new Batiment(WATER_MILL);
        m->setJ(1);
        m1->setJ(1);
        m1->setCombat(30);
        m2->setJ(2);
        c->setJ(1);
        state.getChars().set(6,6,bb);
        state.getChars().set(7,7,b);
        state.getChars().set(3,5,m);
        state.getChars().set(4,4,m1);
        state.getChars().set(5,4,c);
        state.getChars().set(5,5,m2);
        
        //state.getChars().set(7,7,state.getChars().release(3,5));
        
      std::cout<<"crée le moteur à partir de l'état"<<std::endl;
        Engine*eng = new Engine(state);
        std::cout<<"ajoute de nouvelle commande"<< std::endl;
        eng->addCommand(new MoveCommand(3,5,7,7));
        //eng->addCommand(new MoveCommand(4,4,5,6));
        std::cout<<"ajoute de nouvelle commande d'attaque"<< std::endl;
        eng->addCommand(new AttaqueCommand(4,4,5,5));
        eng->addCommand(new MoveCommand(5,4,6,6));
        eng->update();
        std::cout<<"Vérifie les points de vie de l'unité attaqué ont diminué:";
        if (m2->getPv()<100){std::cout<< "OK" <<std::endl ;}else{std::cout<< "Problème sur la commande" <<std::endl;}
        std::cout<<state.getChars().get(5,5)->getTypeId()<<std::endl;
    }
}

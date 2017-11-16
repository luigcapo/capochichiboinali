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
        state.addJoueur(new Joueur(1));
        state.addJoueur(new Joueur(2));
        //ElementTab tabl=ElementTab();
        //tabl = state.getChars();
        Millitary *m=new Millitary(MOUSQUETAIRE);
        Millitary *m1=new Millitary(EPEISTE);
        Colon *c = new Colon();
        Millitary *m2= new Millitary(MOUSQUETAIRE);
        m->setJ(1);
        m1->setJ(1);
        m2->setJ(2);
        c->setJ(1);
        state.getChars().set(3,5,m);
        state.getChars().set(4,4,m1);
        state.getChars().set(5,4,c);
        state.getChars().set(5,5,m2);
        Engine*eng = new Engine(state);
        eng->addCommand(new MoveCommand(3,5,4,4));
        eng->addCommand(new MoveCommand(4,4,5,5));
        eng->addCommand(new AttaqueCommand(4,4,5,5));
        eng->update();
        std::cout<< m2->getPv() <<std::endl;
        
        
                
    }

    
    
}

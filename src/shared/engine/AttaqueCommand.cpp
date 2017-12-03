/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "AttaqueCommand.h"

using namespace state;

namespace engine{

    AttaqueCommand::AttaqueCommand(int x, int y, int x1, int y1):x(x),y(y),x1(x1),y1(y1) {}

    void AttaqueCommand::attaque(state::Military* m, state::Military* m1) {
            m1->setPv(m1->getPv()-m->getCombat());
            
    }

    CommandTypeId AttaqueCommand::getTypeId() const {
        return CommandTypeId::ATTAQUE;
    }

    

    void AttaqueCommand::execute(state::State& state) {
        if(state.getChars().get(x,y)&& state.getChars().get(x1,y1)){
                if(state.getChars().get(x,y)->getTypeId()!=2){}
                else{

                    Military* m=(Military*) state.getChars().get(x,y);
                            if(state.getChars().get(x1,y1)->getTypeId()!=2){}
                            else{
                                 Military*m1=(Military*) state.getChars().get(x1,y1);
                                 //if (m->getX()+1==m1->getX()||m->getY()+1==m1->getY()||m->getX()-1==m1->getX()||m->getY()-1==m1->getY()){
                                 if(m->getJ()!=m1->getJ()){
                                     attaque(m,m1);
                                     if(m1->getPv()<=0){
                                         state.getChars().destroy(x1,y1);
                                         state.getChars().set(x1,y1,state.getChars().release(x,y));
                                     } //CRÉER UNEb COMMANDE KILL DANS LE ElementTab
                                 }
                                 else{}
                           }
                }
    }
    }
}


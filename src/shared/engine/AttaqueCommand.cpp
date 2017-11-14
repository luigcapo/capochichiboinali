/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "AttaqueCommand.h"

using namespace state;

namespace engine{

    void AttaqueCommand::attaque(state::Millitary* m, state::Millitary* m1) {
            m1->setPv(m1->getPv()-m->getCombat());
            if(m1->getPv()<=0){delete (m);}
    }

    CommandTypeId AttaqueCommand::getTypeId() const {
        return CommandTypeId::ATTAQUE;
    }

    

    void AttaqueCommand::execute(state::State& state) {
        for(std::size_t i=0; i< state.getChars().getHeight(); i++){
            for(std::size_t j=0; j< state.getChars().getWidth(); j++){
                if(state.getChars().get(i,j)->getTypeId()!=2){}
                else{
                    Millitary* m=(Millitary*) state.getChars().get(i,j);
                    for(std::size_t k=0; k< state.getChars().getHeight(); k++){
                        for(std::size_t l=0; l< state.getChars().getWidth(); l++){
                             if(state.getChars().get(i,j)->getTypeId()!=2){}
                             else{
                                 Millitary*m1=(Millitary*) state.getChars().get(k,l);
                                 if (m->getX()+1==m1->getX()||m->getY()+1==m1->getY()||m->getX()-1==m1->getX()||m->getY()-1==m1->getY()){
                                     if(m->getJ()!=m1->getJ()){attaque(m,m1);}
                                     else{}
                                 }
                                 else{}   
                             }
                        }
                            
                        
                    }
                    
                    
                    
                }
            }
        }
    }

}
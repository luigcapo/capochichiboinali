/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include "KillAction.h"

using namespace state;

namespace engine{

    KillAction::KillAction(int x, int y, int x1, int y1):x(x),y(y),x1(x1),y1(y1) {}

    
    void KillAction::apply(state::State& state) {
        Military*e=(Military*) state.getChars().get(x1,y1);
        tmp=e->getMilTypeId();
        std::cout<<e->getTypeId()<<std::endl;
        state.getChars().destroy(x1,y1);
        state.getChars().set(x1,y1,state.getChars().release(x,y));
    }

    void KillAction::undo(state::State& state) {
        state.getChars().set(x,y,state.getChars().release(x1,y1));
        state.getChars().set(x1,y1,new Military(tmp));
    }
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "MoveAction.h"

using namespace state;
namespace engine{

    MoveAction::MoveAction(int x, int y, int x1, int y1):x(x),y(y),x1(x1),y1(y1) {}
    
    void MoveAction::apply(state::State& state) {
         state.getChars().set(x1, y1, state.getChars().release(x, y));
    }

    void MoveAction::undo(state::State& state) {
        if(state.getChars().get(x1,y1)){
            state.getChars().set(x,y,state.getChars().release(x1,y1));
        }
    }


}
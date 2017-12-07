/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "AttaqueAction.h"
#include "state/Military.h"

using namespace state;

namespace engine{

    AttaqueAction::AttaqueAction(state::Military* m, state::Military* m1):m(m),m1(m1){}
    
    void AttaqueAction::apply(state::State& state) {
        m1->setPv(m1->getPv()-m->getCombat());
    }
 
    void AttaqueAction::undo(state::State& state) {
        m1->setPv(m1->getPv()+m->getCombat());
    }


}

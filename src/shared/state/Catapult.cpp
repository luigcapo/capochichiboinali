/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Catapult.h"

namespace state{

    Catapult::Catapult() {
        combat = 0;
        pv=100;
        
    }

    int Catapult::getCombat() const {
        return combat;
    }
    
    void Catapult::setCombat(int combat) {
        this->combat=combat;
    }

    int Catapult::getPv() const {
        return pv;
    }
    
    void Catapult::setPv(int pv) {
        this->pv=pv;
    }

    TypeId Catapult::getTypeId() const{
        return TypeId::Catapult;
    }
}
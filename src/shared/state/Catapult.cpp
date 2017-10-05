/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Catapult.h"

namespace state{

    Catapult::Catapult() {
        combat = 0;
    }

    int Catapult::getCombat() const {
        return combat;
    }

    int Catapult::getPv() const {
        return pv;
    }

    const TypeId Catapult::getTypeId() {
        return TypeId::Catapult;
    }

    void Catapult::setCombat(int combat) {
        this->combat=combat;
    }

    void Catapult::setPv(int pv) {
    }





}




/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Military.h"

namespace state{

    Military::Military(MilTypeId id) {
        combat=0;
        pv=100;
        milTypeId = id;
    }
    
    TypeId Military::getTypeId() const{
        return TypeId::MILITARY;
    }

    int Military::getCombat() const {
        return combat;
    }
    
    void Military::setCombat(int combat) {
        this->combat=combat;
    }

    MilTypeId Military::getMilTypeId() const {
        return milTypeId;
    }

    void Military::setMilTypeId(MilTypeId milTypeId) {
        this->milTypeId=milTypeId;
    }
    
    int Military::getPv() const {
        return pv;
    }

    void Military::setPv(int pv) {
        this->pv=pv;
    }
}

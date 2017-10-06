/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Millitary.h"

namespace state{

    Millitary::Millitary(MillTypeId id) {
        combat=0;
        millTypeID=id;
        pv=100;
    }
    
    const TypeId Millitary::getTypeId() {
        return TypeId::Millitary;
    }

    int Millitary::getCombat() const {
        return combat;
    }
    
    void Millitary::setCombat(int combat) {
        this->combat=combat;
    }

    MillTypeId Millitary::getMillTypeID() const {
        return millTypeID;
    }

    void Millitary::setMillTypeID(MillTypeId millTypeID) {
        this->millTypeID=millTypeID;
    }
    
    int Millitary::getPv() const {
        return pv;
    }

    void Millitary::setPv(int pv) {
        this->pv=pv;
    }

}
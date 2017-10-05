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
    }


    int Millitary::getCombat() const {
        return combat;
    }

    MillTypeId Millitary::getMillTypeID() const {
        return millTypeID;
    }


    int Millitary::getPv() const {
        return pv;
    }

    const TypeId Millitary::getTypeId() {
        return TypeId::Millitary;
    }

    void Millitary::setCombat(int combat) {
        this->combat=combat;
    }

    void Millitary::setMillTypeID(MillTypeId millTypeID) {
    
    }

    void Millitary::setPv(int pv) {

    }

}

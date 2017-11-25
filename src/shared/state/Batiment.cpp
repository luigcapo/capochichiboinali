/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Batiment.h"

namespace state {
    
    Batiment::Batiment(BatimentTypeId id) {
        cost = 0;
        pv=0;
        this->batimentTypeId = id;
    }

    BatimentTypeId Batiment::getBatimentTypeId() const{
        return batimentTypeId;
    }

    void Batiment::setBatimentTypeId(BatimentTypeId batimentTypeId) {
        this->batimentTypeId =  batimentTypeId ;
    }

    int Batiment::getCost() const {
        return cost;
    }

    int Batiment::getPv() const {
        return pv;
    }

    void Batiment::setCost(int cost) {
        this->cost= cost;
    }

    void Batiment::setPv(int pv) {
        this->pv=pv;
    }

    TypeId Batiment::getTypeId() const {
        return TypeId::BATIMENT;
    }

}

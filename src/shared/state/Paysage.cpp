/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Paysage.h"

namespace state{

    Paysage::Paysage(PaysageTypeId id) {
        paysageTypeId = id;;
    }
    
    PaysageTypeId Paysage::getPaysageTypeId() const {
        return this->paysageTypeId;
    }

    TypeId Paysage::getTypeId() const {
        return TypeId::PAYSAGE;
    }

    void Paysage::setPaysageTypeId(PaysageTypeId paysageTypeId) {
        this->paysageTypeId = paysageTypeId;
    }

    
}

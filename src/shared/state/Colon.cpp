/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Colon.h"

namespace state{

    Colon::Colon() {
        
    }
    
    TypeId Colon::getTypeId() const{
        return TypeId::Colon;
    }
    bool Catapult::isCatapult() const {
        return false;
    }

    bool Catapult::isColon() const {
        return true;
    }

    bool Catapult::isMillitary() const {
        return false;
    }
}

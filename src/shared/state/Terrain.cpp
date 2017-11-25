/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Plateau.h"

namespace state{

    Plateau::Plateau(PlateauTypeId id) {
        plateautypeId = id;
    }

    PlateauTypeId Plateau::getPlateautypeId() const {
        return plateautypeId;
    }

    void Plateau::setPlateautypeId(PlateauTypeId plateautypeId) {
        this->plateautypeId = plateautypeId;
    }
    
    TypeId Plateau::getTypeId() const{
        return TypeId::PLATEAU;
    }
}

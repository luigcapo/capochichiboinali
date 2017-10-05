/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Space.h"

namespace state{

    /*Space::Space(SpaceTypeId id) {
        spacetypeId = id;
    }*/


    const TypeId Space::getTypeId() {
        return TypeId::Space;
    }

    const bool Space::isSpace() {
        return true;
    }

    void Space::setSpacetypeId(SpaceTypeId spacetypeId) {
        this->spacetypeId = spacetypeId;
    }

}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Ressource.h"
namespace state{

    Ressource::Ressource(RessourceTypeId id) {
        this->ressourceTypeId = id;
    }

    RessourceTypeId Ressource::getRessourceTypeId() const {
        return ressourceTypeId;
    }

    void Ressource::setRessourceTypeId(RessourceTypeId ressourceTypeId) {
        this->ressourceTypeId = ressourceTypeId;
    }
    
    TypeId Ressource::getTypeId() const{
        return TypeId::RESSOURCE;
    }
}

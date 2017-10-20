/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */#include "Colonie.h"

namespace state{

    Colonie::Colonie() {
        cout=0;
    }

    int Colonie::getCout() const {
        return cout;
    }
        
    void Colonie::setCout(int cout) {
        this->cout=cout;
    }
    
    TypeId Colonie::getTypeId() const{
        return TypeId::Colonie;
    }
    bool Plateau::isColonie() const {
        return true;
    }

    bool Plateau::isPlateau() const {
        return false;
    }

    bool Plateau::isRessource() const {
        return false;
    }

    bool Plateau::isWall() const {
        return false;
    }

}

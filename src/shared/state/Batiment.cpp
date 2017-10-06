/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Batiment.h"

namespace state {

    Batiment::Batiment(BatimentTypeId id) {
        cout = 0;
        pv=0;
        this->batimentTypeId = id;
    }

    const BatimentTypeId Batiment::getBatimentTypeId() {
        return batimentTypeId;
    }

    void Batiment::setBatimentTypeId(BatimentTypeId batimentTypeId) {
        this->batimentTypeId =  batimentTypeId ;
    }

    int Batiment::getCout() const {
        return cout;
    }

    int Batiment::getPv() const {
        return pv;
    }

    void Batiment::setCout(int cout) {
        this->cout= cout;
    }

    void Batiment::setPv(int pv) {
        this->pv=pv;
    }

}

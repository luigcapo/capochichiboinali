/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Batiment.h"

namespace state {

    Batiment::Batiment(BatimentTypeId id) {
        this->batimentTypeId = id;
    }

    const BatimentTypeId Batiment::getBatimentTypeId() {
        return batimentTypeId;
    }


    void Batiment::setBatimentTypeId(BatimentTypeId batimentTypeId) {

    }

    int Batiment::getCout() const {

    }

    int Batiment::getPv() const {

    }

    void Batiment::setCout(int cout) {

    }

    void Batiment::setPv(int pv) {

    }

}

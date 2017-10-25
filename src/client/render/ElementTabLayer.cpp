/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ElementTabLayer.h"

namespace render{

    ElementTabLayer::ElementTabLayer(const state::ElementTab& tab) {
        this->tab=tab;
    }

    void ElementTabLayer::initSurface() {
        Surface s;
        //s.loadTexture();
        //s.initQuads();  
    }

}
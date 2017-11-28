/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Element.h"

namespace state{

    Element::Element() {
        x=0;
        y=0;
        j=0;
    }
    
    Element::~Element() {
    }
    
    int Element::getX() const {
        return x; 
    }
    
    void Element::setX(int x) {
        this->x = x;
    }
    
    int Element::getY() const {
        return y;
    }
    
    void Element::setY(int y) {
        this->y = y;
    }

    int Element::getJ() const {
        return j;
    }

    void Element::setJ(int j) {
        this->j=j;
    }

    
}
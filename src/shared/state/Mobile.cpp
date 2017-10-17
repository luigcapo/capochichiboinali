/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Mobile.h"

namespace state {

    Mobile::Mobile() {
        point_mouvement=0;
        cout=0;
    }

    int Mobile::getCout() const {
        return cout;
    }

    int Mobile::getPoint_mouvement() const {
        return point_mouvement;
    }
    
    bool Mobile::isStatic() const{
        return false;
    }

    void Mobile::setCout(int cout) {
        this->cout = cout;
    }

    void Mobile::setPoint_mouvement(int point_mouvement) {
        this->point_mouvement=point_mouvement;
    }

}


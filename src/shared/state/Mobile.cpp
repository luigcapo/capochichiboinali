/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Mobile.h"

namespace state {

    Mobile::Mobile() {
        point_mouvement = 0;
        cost = 0;
    }

    int Mobile::getCost() const {
        return cost;
    }

    int Mobile::getPoint_mouvement() const {
        return point_mouvement;
    }
    
    bool Mobile::isStatic() const{
        return false;
    }

    void Mobile::setCost(int cost) {
        this->cost = cost;
    }

    void Mobile::setPoint_mouvement(int point_mouvement) {
        this->point_mouvement = point_mouvement;
    }
    
    Direction Mobile::getOrientation() const {
        return this->orientation;
    }
        
    void Mobile::setOrientation(Direction orientation) {
        this->orientation = orientation;
    }

}


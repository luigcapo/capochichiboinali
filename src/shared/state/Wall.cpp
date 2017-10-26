/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Wall.h"

namespace state{
    
    Wall::Wall(WallTypeId id) {
        pv=0;
        def=0;
        cout=0;
        
    }
    
    int Wall::getCout() const {
        return cout;
    }
    
    void Wall::setCout(int cout) {
        this->cout=cout;
    }

    int Wall::getDef() const {
        return def;
    }
    
    void Wall::setDef(int def) {
        this->def=def;
    }

    int Wall::getPv() const {
        return pv;
    }
    
    void Wall::setPv(int pv) {
        this->pv=pv;
    }
    
    TypeId Wall::getTypeId() const {
        return TypeId::WALL;
    }

    WallTypeId Wall::getWallTypeId() const {
        return wallTypeId;
    }

    void Wall::setWallTypeId(WallTypeId wallTypeId) {
        this->wallTypeId=wallTypeId;
    }
}

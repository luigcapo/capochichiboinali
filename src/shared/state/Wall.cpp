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

    int Wall::getDef() const {
        return def;
    }

    int Wall::getPv() const {
        return pv;
    }

    const TypeId Wall::getTypeId() {
        return TypeId::Wall;
    }

    WallTypeId Wall::getWallTypeId() const {
        return wallTypeId;
    }

    void Wall::setCout(int cout) {
        this->cout=cout;
    }

    void Wall::setDef(int def) {
        this->def=def;
    }

    void Wall::setPv(int pv) {
        this->pv=pv;
    }

    void Wall::setWallTypeId(WallTypeId wallTypeId) {
        this->wallTypeId=wallTypeId;
    }





}

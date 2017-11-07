/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "CharsTileSet.h"
#include "state.h"

namespace render{

    CharsTileSet::CharsTileSet() {
        millitary.push_back(Tile(0,100,10,10));millitary.push_back(Tile(30,100,10,10));millitary.push_back(Tile(60,100,10,10)); 
        colon.push_back(Tile(80,100,10,10));
        catapult.push_back(Tile(100,100,15,15));
    }

    const std::string CharsTileSet::getImageFile() const {
        return"res/.jpg";
    }

    const Tile& CharsTileSet::getTile(const state::Element& e) const {
        if(e.isStatic()){return *(new Tile);}
        else{
            if(e.getTypeId()==1){return colon[1];}
            else if(e.getTypeId()==2){
                state::Millitary * m = (state::Millitary*)&e;
                if(m->getMillTypeID()==state::EPEISTE){return millitary[1];}
                else if(m->getMillTypeID()==state::MITRAILLEUR){return millitary[2];}
                else{return millitary[3];}
            }
            else{return catapult[1];}
            }
        }
}

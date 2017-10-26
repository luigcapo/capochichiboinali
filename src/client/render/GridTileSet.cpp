/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "GridTileSet.h"

namespace render{

    GridTileSet::GridTileSet() {
        plateau.push_back(Tile());plateau.push_back(Tile());plateau.push_back(Tile());plateau.push_back(Tile());plateau.push_back(Tile());plateau.push_back(Tile()); 
        ressource.push_back(Tile());ressource.push_back(Tile());ressource.push_back(Tile());ressource.push_back(Tile());
        wall.push_back(Tile());wall.push_back(Tile());
        batiment.push_back(Tile());batiment.push_back(Tile());batiment.push_back(Tile());batiment.push_back(Tile());batiment.push_back(Tile());
    }

    /*const std::string GridTileSet::getImageFile() const {
    }*/

    /*const Tile& GridTileSet::getTile(const state::Element& e) const {
        if(!(e.isStatic())){return new Tile();}
        else{
            if (e.getTypeId()==4){
                //Wall w;
                //e=w;
                if (e.wallTypeId==1){
                    return new Tile();
                }
            }
        }
        
    }*/

}
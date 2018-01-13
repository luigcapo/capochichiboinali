/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "TerrainTileSet.h"
#include "state/Terrain.h"

namespace render {

    TerrainTileSet::TerrainTileSet() {
        terrain.push_back(Tile(0, 0, 96, 96)); terrain.push_back(Tile(96, 0, 96, 96));
        terrain.push_back(Tile(192, 0, 96, 96)); terrain.push_back(Tile(288, 0, 96, 96));
        terrain.push_back(Tile(384, 0, 96, 96));
    }

    int TerrainTileSet::getCellHeight() const {
        return 480;
    }
    int TerrainTileSet::getCellWidth() const {
        return 96;
    }

    const std::string TerrainTileSet::getImageFile() const {
        return "res/terrain_tileset.png";
    }

    // Tester pointeur nul
    const Tile& TerrainTileSet::getTile(const state::Element& e) const {
        // Tester si pointeur nul
        
        if( !(e.isStatic()) )
            return *(new Tile);
            
        else{
            
            // TERRAIN
            if(e.getTypeId() == 3){
                state::Terrain* t = (state::Terrain*)&e;
                
                if(t->getTerrainTypeId() == state::PLAINE)
                    return terrain[0];
                else if(t->getTerrainTypeId() == state::DESERT)
                    return terrain[1];
                else if(t->getTerrainTypeId() == state::NEIGE)
                    return terrain[2];
                else // MOUNTAIN
                    return terrain[4];
            } 
        }
        return *(new Tile);
    }
    
    
}

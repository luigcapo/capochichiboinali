/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "TerrainTileSet.h"
#include "state/Terrain.h"

namespace render {

    TerrainTileSet::TerrainTileSet() {
        
    }


    int TerrainTileSet::getCellHeight() const {
        return 768;
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
                    return *( new Tile(0, 0, 96, 96) );
                else if(t->getTerrainTypeId() == state::DESERT)
                    return *( new Tile(96, 0, 96, 96) );
                else if(t->getTerrainTypeId() == state::NEIGE)
                    return *( new Tile(192, 0, 96, 96) );
                else // MOUNTAIN
                    return *( new Tile(384, 0, 96, 96) );
            } 
        }
        return *(new Tile);
    }
    
    
}

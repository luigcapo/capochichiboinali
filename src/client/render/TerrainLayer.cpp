/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "TerrainLayer.h"
#include "TerrainTileSet.h"

namespace render {

    TerrainLayer::TerrainLayer(const state::ElementTab& tab):tab(tab) {
        this->tileset.reset(new TerrainTileSet());
    }

    void TerrainLayer::initSurface() {
        // fabrique une nouvelle surface
        this->surface.reset(new Surface());   
        // demande à la surface de charger la texture
        surface->loadTexture(tileset->getImageFile());     
        // on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
        surface->initQuads( tab.getWidth() * tab.getHeight() );      
        // on initialise la liste des sprites
        for ( std::size_t i=0; i<tab.getWidth(); i++ ){
            for( std::size_t j=0; j<tab.getHeight(); j++ ){
                if (tab.get(i, j)) {
                    surface->setSpriteLocation( i+j*tab.getWidth(), i, j );
                    surface->setSpriteTexture( i+j*tab.getWidth(), tileset->getTile(*tab.get(i, j)) );
                }
            }
        }
    }

}

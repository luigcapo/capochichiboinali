/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "CharsLayer.h"
#include "CharsTileSet.h"

namespace render{

    CharsLayer::CharsLayer(const state::ElementTab& tab):tab(tab) {
        this->tileset.reset(new CharsTileSet());
    }

    void CharsLayer::initSurface() {
        this->surface.reset(new Surface());
        surface->loadTexture(tileset->getImageFile());
        surface->initQuads( tab.getWidth() * tab.getHeight() );
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

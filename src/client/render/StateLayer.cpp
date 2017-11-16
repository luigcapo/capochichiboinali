/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "StateLayer.h"
#include "CharsTileSet.h"

namespace render{

    // on enregistre un ElementTab(chars -> liste des personnages) dans l'attribut tab
    StateLayer::StateLayer (const state::ElementTab& state):state(state) {
    }

    // va afficher la liste des personnages
    void StateLayer::initSurface() {
        // fabrique une nouvelle surface
        tileset = std::shared_ptr<TileSet>(new CharsTileSet());
        surface = std::unique_ptr<Surface>(new Surface());
        
        // demande à la surface de charger la texture
        surface->loadTexture( tileset->getImageFile() );
        
        // on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
        surface->initQuads( (state.getWidth()) * (state.getHeight()) );
        
        // on initialise la liste des sprites
        for ( std::size_t i=0; i<state.getWidth(); i++ ){
            for( std::size_t j=0; j<state.getHeight(); j++ ){
                
                // surface->setSpriteLocation( (i+j*tab.getWidth()), tab.get(i, j)->getX(), tab.get(i, j)->getY() );
                surface->setSpriteLocation( (i+j*state.getWidth()), i, j, tileset->getTile(*state.get(i, j)) );
                surface->setSpriteTexture( (i+j*state.getWidth()), tileset->getTile(*state.get(i, j)) ); 
            }
        }
    }
    

}
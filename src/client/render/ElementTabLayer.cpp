/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ElementTabLayer.h"
#include "GridTileSet.h"
#include "CharsTileSet.h"

namespace render{

    // on enregistre un ElementTab(grid) dans l'attribut tab
    ElementTabLayer::ElementTabLayer(const state::ElementTab& tab):tab(tab) {}
    
    // va afficher la grille des éléments du niveau
    void ElementTabLayer::initSurface() {
        
        // fabrique une nouvelle surface
        tileset = std::shared_ptr<TileSet>(new GridTileSet());
        surface = std::unique_ptr<Surface>(new Surface());
        
        // demande à la surface de charger la texture
        surface->loadTexture( tileset->getImageFile() );
        
        // on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
        surface->initQuads( (tab.getWidth()) * (tab.getHeight()) );
        
        // on initialise la liste des sprites
        for ( std::size_t i=0; i<tab.getWidth(); i++ ){
            for( std::size_t j=0; j<tab.getHeight(); j++ ){
                
                // setSpriteLocation (int i, int x, int y, const Tile& tex)
                // surface->setSpriteLocation( (i+j*tab.getWidth()), tab.get(i, j)->getX(), tab.get(i, j)->getY() );
                surface->setSpriteLocation( (i+j)*tab.getWidth(), i, j, tileset->getTile(*tab.get(i, j)) );
                surface->setSpriteTexture( (i+j*tab.getWidth()), tileset->getTile(*tab.get(i, j)) ); 
            }
        }  
        
    }
    
    
}
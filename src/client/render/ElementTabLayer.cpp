/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ElementTabLayer.h"
#include "GridTileSet.h"
#include "CharsTileSet.h"
#include "TerrainTileSet.h"
#include "state/ElementTab.h"

namespace render{

    // on enregistre un ElementTab(grid) dans l'attribut tab
    ElementTabLayer::ElementTabLayer (const state::ElementTab& tab, int id):id(id), tab(tab) {
        
        // id pour initialiser le tileset
        // id=1 --->terrain
        // id=2 --->grid
        // id=3 --->chars
        if(id == 1)
            this->tileset.reset(new TerrainTileSet());
        
        else if(id == 2)
            this->tileset.reset(new GridTileSet());
        
        else if(id == 3)
            this->tileset.reset(new CharsTileSet());
    }
    
    
    
    
    // on affiche la grille des éléments du niveau
    void ElementTabLayer::initSurface() {
        
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
    }   // initSurface();
     
    
}
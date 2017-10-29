/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ElementTabLayer.h"

namespace render{

    ElementTabLayer::ElementTabLayer(const state::ElementTab& tab):tab(tab) {}

    void ElementTabLayer::initSurface() {
        Surface s;
        s.loadTexture(tileset->getImageFIle());
        for (unsigned int i=0;i<tab.getHeight();i++){
            for(unsigned int j=0;j<tab.getWidth();j++){
                Tile tile=tileset->getTile(*(tab.get(i,j)));
                    s.initQuads(tile.getHeight()*tile.getWidth());
            }
        }
        
          
    }
    
}
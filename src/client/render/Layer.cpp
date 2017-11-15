/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Layer.h"
#include "GridTileSet.h"

namespace render{

    Layer::Layer() {
        this->surface = std::unique_ptr<Surface>(new Surface());
        this->tileset = nullptr;
        
        //std::shared_ptr<TileSet> Grid(new TileSet());
    }

    const Surface* Layer::getSurface() const {
        return &(*(this->surface));
    }

    void Layer::setSurface(Surface* surface) {
        *(this->surface) = *surface;
    }

    Layer::~Layer() {
    }

}
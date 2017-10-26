/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Layer.h"

namespace render{

    Layer::Layer() {
        this->surface=std::unique_ptr<Surface>(new Surface());
        this->tileset=nullptr;
    }

    const Surface* Layer::getSurface() const {
        return &(*(this->surface));
    }

    const std::shared_ptr<TileSet>& Layer::getTileset() const {
        return tileset;
    }

    void Layer::setSurface(Surface* surface) {
        *(this->surface) = *surface;
    }

    void Layer::setTileset(const std::shared_ptr<TileSet>& tileset) {
        this->tileset=tileset;
    }

    Layer::~Layer() {
    }

}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Terrain.h"

namespace state {

    bool Terrain::IsTerrain() const {
        return true;
    }

    Terrain::Terrain(TerrainTypeId id) {
        this->terrainTypeId = id;
    }

    TerrainTypeId Terrain::getTerrainTypeId() const {
        return this->terrainTypeId;
    }

    TypeId Terrain::getTypeId() const {
        return TypeId::TERRAIN;
    }

    void Terrain::setTerrainTypeId(TerrainTypeId terrainTypeId) {
        this->terrainTypeId = terrainTypeId;
    }
    
}

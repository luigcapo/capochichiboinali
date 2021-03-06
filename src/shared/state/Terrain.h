// Generated by dia2code
#ifndef STATE__TERRAIN__H
#define STATE__TERRAIN__H


namespace state {
  class Static;
}

#include "TerrainTypeId.h"
#include "TypeId.h"
#include "Static.h"

namespace state {

  /// class Terrain - 
  class Terrain : public state::Static {
    // Associations
    state::TerrainTypeId terrainTypeId;
    // Operations
  public:
    Terrain (TerrainTypeId id);
    TypeId getTypeId () const;
    bool IsTerrain () const;
    // Setters and Getters
    TerrainTypeId getTerrainTypeId() const;
    void setTerrainTypeId(TerrainTypeId terrainTypeId);
  };

};

#endif

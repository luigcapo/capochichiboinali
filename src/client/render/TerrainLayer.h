// Generated by dia2code
#ifndef RENDER__TERRAINLAYER__H
#define RENDER__TERRAINLAYER__H


namespace state {
  class ElementTab;
};
namespace render {
  class Layer;
}

#include "Layer.h"
#include "state/ElementTab.h"

namespace render {

  /// class TerrainLayer - 
  class TerrainLayer : public render::Layer {
    // Associations
    // Attributes
  private:
    const state::ElementTab& tab;
    // Operations
  public:
    TerrainLayer (const state::ElementTab& tab);
    void initSurface ();
    // Setters and Getters
  };

};

#endif

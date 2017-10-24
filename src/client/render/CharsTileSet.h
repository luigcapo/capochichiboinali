// Generated by dia2code
#ifndef RENDER__CHARSTILESET__H
#define RENDER__CHARSTILESET__H

#include <vector>

namespace render {
  class Tile;
  class TileSet;
}

#include "Tile.h"
#include "TileSet.h"

namespace render {

  /// class CharsTileSet - 
  class CharsTileSet : public render::TileSet {
    // Attributes
  private:
    std::vector<Tile> millitary;
    std::vector<Tile> colon;
    std::vector<Tile> catapult;
    // Operations
  public:
    CharsTileSet ();
    int getCellWidth () const;
    int getCellHeight () const;
    int getImageFile () const;
    virtual const Tile& getTile ( e const state::Element&) const;
    // Setters and Getters
  };

};

#endif
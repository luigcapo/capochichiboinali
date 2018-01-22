// Generated by dia2code
#ifndef CLIENT__CLIENT__H
#define CLIENT__CLIENT__H


namespace ai {
  class RandomAI;
};
namespace state {
  class State;
};
namespace render {
  class TerrainLayer;
  class CharsLayer;
  class GridLayer;
};
namespace engine {
  class Engine;
}

#include "ai/RandomAI.h"
#include "state/State.h"
#include "render/TerrainLayer.h"
#include "render/CharsLayer.h"
#include "render/GridLayer.h"
#include "engine/Engine.h"

namespace client {

  /// class Client - 
  class Client {
    // Associations
    // Attributes
  private:
    ai::RandomAI random;
    state::State state;
    // Operations
  public:
    Client ();
    void run ();
    // Setters and Getters
  };

};

#endif

// Generated by dia2code
#ifndef AI__DEEPAI__H
#define AI__DEEPAI__H


namespace state {
  class State;
};
namespace engine {
  class Engine;
};
namespace ai {
  class AI;
  class PathMap;
}

#include "AI.h"
#include "PathMap.h"

namespace ai {

  /// class DeepAI - 
  class DeepAI : public ai::AI {
    // Associations
    // Attributes
  private:
    int updatesCount     = 0;
  protected:
    int maxDepth     = 6;
    int maxUpdates     = 5000;
    // Operations
  public:
    DeepAI (const state::State& state);
    void run (engine::Engine& engine);
  protected:
    int minimin_rec (engine::Engine& engine, state::Direction& bestdir, int depth);
    // Setters and Getters
    int getMaxDepth() const;
    void setMaxDepth(int maxDepth);
    int getMaxUpdates() const;
    void setMaxUpdates(int maxUpdates);
  };

};

#endif

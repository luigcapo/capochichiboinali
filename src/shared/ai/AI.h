// Generated by dia2code
#ifndef AI__AI__H
#define AI__AI__H

#include <vector>

namespace engine {
  class Command;
};
namespace state {
  class Element;
};
namespace engine {
  class Engine;
}

#include "state/Element.h"
#include "engine/Command.h"
#include "engine/Engine.h"

namespace ai {

  /// class AI - 
  class AI {
    // Operations
  public:
    void listCommands (std::vector<engine::Command*>& list, state::Element* e);
    virtual void run  (engine::Engine& engine) = 0;
    // Setters and Getters
  };

};

#endif

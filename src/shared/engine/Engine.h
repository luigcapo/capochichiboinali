// Generated by dia2code
#ifndef ENGINE__ENGINE__H
#define ENGINE__ENGINE__H

#include <vector>
#include <memory>

namespace state {
  class State;
};
namespace engine {
  class Command;
}

#include "state/State.h"
#include "Command.h"

namespace engine {

  /// class Engine - 
  class Engine {
    // Associations
    // Attributes
  private:
    state::State currentState;
    std::vector<std::unique_ptr<Command>> currentCommands;
    // Operations
  public:
    Engine ();
    ~Engine ();
    const state::State& getState ();
    void addCommand (Command* cmd);
    void update ();
    // Setters and Getters
  };

};

#endif

// Generated by dia2code
#ifndef ENGINE__ENGINE__H
#define ENGINE__ENGINE__H

#include <vector>
#include <stack>

namespace state {
  class State;
};
namespace engine {
  class Command;
  class Action;
}

#include "Command.h"

namespace engine {

  /// class Engine - 
  class Engine {
    // Associations
    // Attributes
  private:
    state::State& currentState;
    std::vector<Command*> currentCommands;
    // Operations
  public:
    Engine (state::State& state);
    ~Engine ();
    state::State& getState () const;
    void addCommand (Command* cmd);
    void resize (int c);
    std::stack<Action*> update ();
    void executeCom (Command* c);
    void undo (std::stack<Action*>& actions);
    // Setters and Getters
  };

};

#endif

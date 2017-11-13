// Generated by dia2code
#ifndef ENGINE__FONDATIONCOMMAND__H
#define ENGINE__FONDATIONCOMMAND__H


namespace state {
  class Colon;
  class State;
};
namespace engine {
  class Command;
}

#include "CommandTypeId.h"
#include "Command.h"
#include "state/Colon.h"

namespace engine {

  /// class FondationCommand - 
  class FondationCommand : public engine::Command {
    // Operations
  public:
    void fonda (state::Colon* c);
    CommandTypeId getTypeId () const;
    void execute (state::State& state);
    // Setters and Getters
  };

};

#endif

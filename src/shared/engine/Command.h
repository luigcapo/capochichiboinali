// Generated by dia2code
#ifndef ENGINE__COMMAND__H
#define ENGINE__COMMAND__H


namespace engine {
  class CommandTypeId;
};
namespace state {
  class State;
}

#include "CommandTypeId.h"
#include "state/State.h"

namespace engine {

  /// class Command - 
  class Command {
    // Operations
  public:
    virtual ~Command ();
    virtual CommandTypeId getTypeId () const = 0;
    virtual void execute (state::State& state) = 0;
    // Setters and Getters
  };

};

#endif

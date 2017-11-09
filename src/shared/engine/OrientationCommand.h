// Generated by dia2code
#ifndef ENGINE__ORIENTATIONCOMMAND__H
#define ENGINE__ORIENTATIONCOMMAND__H


namespace state {
  class State;
};
namespace engine {
  class Command;
}

#include "state/Direction.h"
#include "CommandTypeId.h"
#include "Command.h"

namespace engine {

  /// class OrientationCommand - 
  class OrientationCommand : public engine::Command {
    // Associations
    // Attributes
  protected:
    int character;
    state::Direction orientation;
    // Operations
  public:
    OrientatonCommand (int c, state::Direction d);
    CommandTypeId getTypeId () const;
    execute (state::State& state);
    // Setters and Getters
    int getCharacter() const;
    void setCharacter(int character);
    state::Direction getOrientation() const;
    void setOrientation(state::Direction orientation);
  };

};

#endif

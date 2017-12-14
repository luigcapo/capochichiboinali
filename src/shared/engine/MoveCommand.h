// Generated by dia2code
#ifndef ENGINE__MOVECOMMAND__H
#define ENGINE__MOVECOMMAND__H

#include <stack>
#include <json/json.h>

namespace state {
  class State;
};
namespace engine {
  class Action;
  class MoveCommand;
  class Command;
}

#include "state/Direction.h"
#include "CommandTypeId.h"
#include "Command.h"

namespace engine {

  /// class MoveCommand - 
  class MoveCommand : public engine::Command {
    // Associations
    // Attributes
  private:
    int x;
    int y;
    int x1;
    int y1;
  protected:
    int character;
    state::Direction d;
    // Operations
  public:
    MoveCommand (int x, int y, int  x1, int y1);
    bool trymove (state::State& state) const;
    CommandTypeId getTypeId () const;
    void execute (state::State& state, std::stack<Action*>& s);
    void serialized (Json::Value& out) const;
    MoveCommand* deserialized (Json::Value& out);
    // Setters and Getters
    int getCharacter() const;
    void setCharacter(int character);
    state::Direction getD() const;
    void setD(state::Direction d);
  };

};

#endif

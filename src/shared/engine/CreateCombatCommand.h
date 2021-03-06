// Generated by dia2code
#ifndef ENGINE__CREATECOMBATCOMMAND__H
#define ENGINE__CREATECOMBATCOMMAND__H

#include <stack>
#include <json/json.h>

namespace state {
  class Military;
  class State;
};
namespace engine {
  class Action;
  class CreateCombatCommand;
  class Command;
}

#include "state/MilTypeId.h"
#include "CommandTypeId.h"
#include "Command.h"

namespace engine {

  /// class CreateCombatCommand - 
  class CreateCombatCommand : public engine::Command {
    // Attributes
  private:
    state::Military* unit;
    int x;
    int y;
    // Operations
  public:
    CreateCombatCommand (state::MilTypeId m, int x, int y);
    void execute (state::State& state, std::stack<Action*>& s);
    bool tryCreateChars (state::State& state) const;
    ~CreateCombatCommand ();
    CommandTypeId getTypeId () const;
    void serialized (Json::Value& out) const;
    static CreateCombatCommand* deserialized (Json::Value& in);
    // Setters and Getters
  };

};

#endif

// Generated by dia2code
#ifndef ENGINE__ATTAQUECOMMAND__H
#define ENGINE__ATTAQUECOMMAND__H

#include <stack>
#include <json/json.h>

namespace state {
  class Military;
  class State;
};
namespace engine {
  class Action;
  class AttaqueCommand;
  class Command;
}

#include "CommandTypeId.h"
#include "Command.h"
#include "state/Military.h"

namespace engine {

  /// class AttaqueCommand - 
  class AttaqueCommand : public engine::Command {
    // Attributes
  public:
    int x;
  private:
    int y;
    int x1;
    int y1;
    // Operations
  public:
    AttaqueCommand (int x, int y, int x1, int y1);
    void attaque (state::Military* m, state::Military* m1);
    CommandTypeId getTypeId () const;
    void execute (state::State& state, std::stack<Action*>& s);
    void serialized (Json::Value& out) const;
    static AttaqueCommand* deserialized (Json::Value& in);
    // Setters and Getters
  };

};

#endif

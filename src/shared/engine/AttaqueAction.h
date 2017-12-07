// Generated by dia2code
#ifndef ENGINE__ATTAQUEACTION__H
#define ENGINE__ATTAQUEACTION__H


namespace state {
  class Military;
  class State;
};
namespace engine {
  class Action;
}

#include "Action.h"

namespace engine {

  /// class AttaqueAction - 
  class AttaqueAction : public engine::Action {
    // Attributes
  protected:
    state::Military* m;
    state::Military* m1;
    // Operations
  public:
    AttaqueAction (state::Military* m, state::Military* m1);
    void apply (state::State& state);
    void undo (state::State& state);
    // Setters and Getters
    const state::Military*& getM() const;
    void setM(const state::Military*& m);
    const state::Military*& getM1() const;
    void setM1(const state::Military*& m1);
  };

};

#endif
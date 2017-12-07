// Generated by dia2code
#ifndef ENGINE__MOVEACTION__H
#define ENGINE__MOVEACTION__H


namespace state {
  class State;
};
namespace engine {
  class Action;
}

#include "Action.h"

namespace engine {

  /// class MoveAction - 
  class MoveAction : public engine::Action {
    // Attributes
  protected:
    int x;
    int y;
    int x1;
    int y1;
    // Operations
  public:
    MoveAction (int x, int y, int x1, int y1);
    void apply (state::State& state);
    void undo (state::State& state);
    // Setters and Getters
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
    int getX1() const;
    void setX1(int x1);
    int getY1() const;
    void setY1(int y1);
  };

};

#endif
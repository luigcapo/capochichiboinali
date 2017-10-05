// Generated by dia2code
#ifndef STATE__WALL__H
#define STATE__WALL__H


namespace state {
  class Static;
}

#include "WallTypeId.h"
#include "Static.h"

namespace state {

  /// class Wall - 
  class Wall : public state::Static {
    // Associations
    state::WallTypeId wallTypeId;
    // Attributes
  protected:
    int pv;
    int def;
    int cout;
    // Operations
  public:
    Wall (WallTypeId id);
    TypeId const getTypeId ();
    bool const isStatic ();
    bool const isSpace ();
    // Setters and Getters
    WallTypeId getWallTypeId() const;
    void setWallTypeId(WallTypeId wallTypeId);
    int getPv() const;
    void setPv(int pv);
    int getDef() const;
    void setDef(int def);
    int getCout() const;
    void setCout(int cout);
  };

};

#endif

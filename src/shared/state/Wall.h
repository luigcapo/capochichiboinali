// Generated by dia2code
#ifndef STATE__WALL__H
#define STATE__WALL__H

#include <string>

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
  public:
    std::string name;
  protected:
    int pv;
    int def;
    int cout;
    // Operations
  public:
    Wall (WallTypeId id);
    TypeId const getTypeId ();
    WallTypeId const getWallTypeId ();
    // Setters and Getters
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

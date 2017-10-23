// Generated by dia2code
#ifndef STATE__MILLITARY__H
#define STATE__MILLITARY__H


namespace state {
  class Mobile;
}

#include "MillTypeId.h"
#include "TypeId.h"
#include "Mobile.h"

namespace state {

  /// class Millitary - 
  class Millitary : public state::Mobile {
    // Associations
    state::MillTypeId millTypeID;
    // Attributes
  protected:
    int combat;
    int pv     = 100;
    // Operations
  public:
    Millitary (MillTypeId id);
    TypeId getTypeId () const;
    // Setters and Getters
    MillTypeId getMillTypeID() const;
    void setMillTypeID(MillTypeId millTypeID);
    int getCombat() const;
    void setCombat(int combat);
    int getPv() const;
    void setPv(int pv);
  };

};

#endif

// Generated by dia2code
#ifndef STATE__BATIMENT__H
#define STATE__BATIMENT__H


#include "BatimentTypeId.h"

namespace state {

  /// class Batiment - 
  class Batiment {
    // Associations
    state::BatimentTypeId batimentTypeId;
    // Attributes
  protected:
    int pv;
    int cout;
    // Operations
  public:
    Batiment (BatimentTypeId id);
    BatimentTypeId getBatimentTypeId () const;
    // Setters and Getters
    void setBatimentTypeId(BatimentTypeId batimentTypeId);
    int getPv() const;
    void setPv(int pv);
    int getCout() const;
    void setCout(int cout);
  };

};

#endif

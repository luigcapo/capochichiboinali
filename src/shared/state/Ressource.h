// Generated by dia2code
#ifndef STATE__RESSOURCE__H
#define STATE__RESSOURCE__H


namespace state {
  class Space;
}

#include "RessourceTypeId.h"
#include "Space.h"

namespace state {

  /// class Ressource - 
  class Ressource : public state::Space {
    // Associations
    state::RessourceTypeId ressourceTypeId;
    // Operations
  public:
    Ressource (RessourceTypeId id);
    SpaceTypeId const getSpaceTypeId ();
    // Setters and Getters
    RessourceTypeId getRessourceTypeId() const;
    void setRessourceTypeId(RessourceTypeId ressourceTypeId);
  };

};

#endif

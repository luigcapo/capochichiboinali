// Generated by dia2code
#ifndef STATE__STATIC__H
#define STATE__STATIC__H


namespace state {
  class Element;
}

#include "Element.h"

namespace state {

  /// class Static - 
  class Static : public state::Element {
    // Operations
  public:
    virtual bool const isStatic () = 0;
    // Setters and Getters
  };

};

#endif
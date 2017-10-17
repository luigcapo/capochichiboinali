// Generated by dia2code
#ifndef STATE__ELEMENTTAB__H
#define STATE__ELEMENTTAB__H

#include <stdlib.h>
#include <vector>
#include <memory>

namespace state {
  class Element;
}

namespace state {

  /// class ElementTab - 
  class ElementTab {
    // Attributes
  private:
    size_t width;
    size_t height;
    std::vector<std::unique_ptr<Element>> list;
    // Operations
  public:
    ElementTab (size_t width = 0, size_t height = 1);
    size_t add (Element* e);
    void resize (size_t width, size_t height);
    Element* get (int i, int j = 0) const;
    // Setters and Getters
  };

};

#endif
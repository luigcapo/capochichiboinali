// Generated by dia2code
#ifndef STATE__ELEMENTTAB__H
#define STATE__ELEMENTTAB__H

#include <stdlib.h>
#include <vector>
#include <memory>
#include <string>

namespace state {
  class Element;
}

#include "Element.h"

namespace state {

  /// class ElementTab - 
  class ElementTab {
    // Associations
    // Attributes
  private:
    std::size_t width;
    std::size_t height;
    std::vector<std::unique_ptr<Element>> list;
    bool map1;
    // Operations
  public:
    ElementTab ();
    ElementTab (int width, int height);
    std::size_t getWidth () const;
    std::size_t getHeight () const;
    void add (Element* e);
    void resize (std::size_t width, std::size_t height);
    Element* get (std::size_t i, std::size_t j) const;
    void set (std::size_t i, std::size_t j, Element* e);
    std::size_t size () const;
    void load (const std::string& file);
    Element* getChar (int i) const;
    void setChar (int i, Element* e);
    bool getMap1 () const;
    void setMap2 ();
    // Setters and Getters
  };

};

#endif

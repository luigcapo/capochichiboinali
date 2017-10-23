/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ElementTab.h"

namespace state{

    ElementTab::ElementTab (int width, int height) {
        this->width = width;
        this->height = height;
    }
    
    int ElementTab::getWidth () const {
        return this->width;
    }
    
    int ElementTab::getHeight () const {
        return this->height;
    }

    void ElementTab::add (Element* e) {
        list.push_back(std::unique_ptr<state::Element>(e));
    }
    
    Element* ElementTab::get (int i, int j) const {
        return list[i+j*width].get();
    }

    void ElementTab::set (int i, int j, Element* e) {
        //list[i,j] = e;
    }

}

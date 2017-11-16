/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ElementTab.h"

namespace state{
    
    ElementTab::ElementTab() {
        this->width = 0;
        this->height = 1;
    }
    
    std::size_t ElementTab::getWidth () const {
        return this->width;
    }
    
    std::size_t ElementTab::getHeight () const {
        return this->height;
    }

    void ElementTab::add (Element* e) {
        list.push_back(std::unique_ptr<state::Element>(e));
        //this->width+=1;
    }
    
    Element* ElementTab::get (std::size_t i, std::size_t j) const {
        return list[i+j*width].get();
    }

    void ElementTab::set (std::size_t i, std::size_t j, Element* e) {
        list[i+j*width] = std::unique_ptr<state::Element>(e);
    }
    
    std::size_t ElementTab::size () const{
        return list.size();   
    }
    
    void ElementTab::resize (std::size_t width, std::size_t height) {
        
        this->width = width;
        this->height = height;
        list.resize(width*height);
    }
}

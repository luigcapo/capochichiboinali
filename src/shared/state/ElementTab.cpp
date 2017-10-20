/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ElementTab.h"

namespace state{

    ElementTab::ElementTab(size_t width, size_t height) {
        this->width = width;
        this->height = height;
    }

    void ElementTab::add(Element* e) {
        list.push_back(&e);
    }
    
    Element* ElementTab::get(int i, int j) const {
        return ElementTab[i,j];
    }

    size_t ElementTab::getHeight() const {
        return height;
    }

    size_t ElementTab::getWidth() const {
        return width;
    }

    void ElementTab::set(int i, int j, Element* e) {

    }





}

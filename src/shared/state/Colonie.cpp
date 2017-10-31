/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Colonie.h"

namespace state{
    Colonie::Colonie() {
        name="";
    }

    const std::string& Colonie::getName() const {
        return name;
    }

    void Colonie::setName(const std::string& name) {
        this->name = name;
    }

    void Colonie::add(Element* e) {
        groupe.push_back(std::unique_ptr<state::Element>(e));
    }

    
   
}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "State.h"

namespace state{
        
    ElementTab& State::getChars() {
        return this->chars;
    }
    
    ElementTab& State::getGrid() {
        return this->grid;
    } 
}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "State.h"

namespace state{
        
    ElementTab& State::getChars() {
        return chars;
    }
    
    const ElementTab& State::getChars () const {
        return chars;
    }
    
    ElementTab& State::getGrid() {
        return this->grid;
    }
    
    const ElementTab& State::getGrid () const {
        return grid;
    }
    
    ElementTab& State::getTerrain() {
        return this->terrain;
    }
    
    const ElementTab& State::getTerrain () const {
        return terrain;
    }

    void State::addJoueur(Joueur* j) {
        listJoueur.push_back(j);
    }

    int State::getNumber() const{
        return number;
    }

    void State::setNumber(int n) {
        number = n;
    }

    int State::getEpoch() const {
        return epoch;
    }

    void State::setEpoch(int epoch) {
        this->epoch = epoch;
    }
    
}
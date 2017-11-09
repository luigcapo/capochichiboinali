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
    
    ElementTab& State::getGrid() {
        return this->grid;
    }

    void State::addJoueur(Joueur* j) {
        listJoueur.push_back(j);
    }

}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Joueur.h"

namespace state{

    Joueur::Joueur(int i) {
        id=i;
    }

    void Joueur::addCity(Colonie* c) {
        listColonies.push_back(std::unique_ptr<Colonie>(c));
    }

    int Joueur::getId() const {
        return id;
    }
    const std::vector<std::unique_ptr<Colonie> >& Joueur::getListColonies() const {
        return listColonies;
    }


}
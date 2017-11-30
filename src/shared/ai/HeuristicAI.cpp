/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "HeuristicAI.h"

namespace ai{
    
    HeuristicAI::HeuristicAI(const state::State& state) {
        
    }
    
    const PathMap& HeuristicAI::getBatJoueur1Map() const {
        return this->batJoueur1Map;
    }

    const PathMap& HeuristicAI::getBatJoueur2Map() const {
        return this->batJoueur2Map;
    }

    const PathMap& HeuristicAI::getUnitJoueur1Map() const {
        return this->unitJoueur1Map;
    }

    const PathMap& HeuristicAI::getUnitJoueur2Map() const {
        return this->unitJoueur2Map;
    }

    void HeuristicAI::run(engine::Engine& engine) {
        
    }
    
}
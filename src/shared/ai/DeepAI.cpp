/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "DeepAI.h"

namespace ai {

    DeepAI::DeepAI(const state::State& state) {
        
    }

    int DeepAI::getMaxDepth() const {
        return this->maxDepth;
    }

    int DeepAI::getMaxUpdates() const {
        return this->maxUpdates;
    }

    void DeepAI::setMaxDepth(int maxDepth) {
        this->maxDepth = maxDepth;
    }

    void DeepAI::setMaxUpdates(int maxUpdates) {
        this->maxUpdates = maxUpdates;
    }
    
    int DeepAI::minimin_rec(engine::Engine& engine, state::Direction& bestdir, int depth) {
        
    }
    
    void DeepAI::run(engine::Engine& engine) {
        
    }
    
}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "HandleCollisionsCommand.h"

namespace engine{
    void HandleCollisionsCommand::TestCollisions() {
        
    }

    void HandleCollisionsCommand::execute(state::State& state) {
        TestCollisions();
    }

    CommandTypeId HandleCollisionsCommand::getTypeId() const {
        
    }
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Engine.h"

namespace engine{

    Engine::Engine() {
        
    }

    Engine::~Engine() {
        
    }
    
    void Engine::addCommand(Command* cmd) {
        currentCommands.push_back(std::unique_ptr<Command>(cmd));
    }

    const state::State& Engine::getState() {
        return currentState;
    }

    void Engine::update() {
        for(auto& command : currentCommands){
            command->execute( currentState);
        }
    }

}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Engine.h"

namespace engine {
    Engine::Engine(state::State& state):currentState(state) {

    }


    Engine::~Engine() {
        for (auto command:currentCommands){delete command;}
    }
    
    void Engine::addCommand(Command* cmd) {
        currentCommands.push_back(cmd);
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
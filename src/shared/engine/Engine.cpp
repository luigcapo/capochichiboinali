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

    void Engine::resize(int c) {
        currentCommands.resize(c);
    }


    void Engine::addCommand(Command* cmd) {
        currentCommands.push_back(cmd);
    }
    state::State& Engine::getState() const {
        return currentState;
    }

    
    void Engine::update() {
        for(auto command : currentCommands){
            command->execute(currentState);
        }
    }

    void Engine::execute(Command* c) {
        c->execute(currentState);
    }

}
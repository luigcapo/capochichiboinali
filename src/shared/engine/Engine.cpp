/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <fstream>
#include "Engine.h"
#include "state/State.h"
#include <thread>
#include "unistd.h"
#include <iostream>

using namespace std;

namespace engine { 

    Engine::Engine(state::State& state):currentState(state) {

    }

    void Engine::undo(std::stack<Action*>& actions) {
        while(!actions.empty()){
            
            actions.top()->undo(currentState);
            actions.pop();
        }
    }

    void Engine::runThread (ai::AI* random) {
        std::lock_guard<std::mutex> l(engine_mutex);
        while(1){
            if(run_randomAI == true){
                random->run(*this);
                run_randomAI=false;
            }
        }
    }

    bool Engine::getRun_randomAI() const {
        std::lock_guard<std::mutex> l(std::mutex);
        return this->run_randomAI;
    }

    void Engine::setRun_randomAI(bool run_randomAI) {
        std::lock_guard<std::mutex> l(std::mutex);
        this->run_randomAI = run_randomAI;
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

    
    std::stack<Action*> Engine::update() {
        std::stack<Action*> actions;
        for(auto command : currentCommands){
            command->execute(currentState,actions);
        }
        currentCommands.clear();
        return actions;
    }

    void Engine::executeCom(Command* c) {
        //c->execute(currentState);
    }

    std::stack<Action*> Engine::updateReplay() {
        std::stack<Action*> actions;
        Json::Value record1;
        
        for(auto command : currentCommands){
            Json::Value record2;
            command->serialized(record2);
            command->execute(currentState,actions);
            record1.append(record2);
            
        }
        
        currentCommands.clear();
        record.append(record1);
        return actions;
    }
}
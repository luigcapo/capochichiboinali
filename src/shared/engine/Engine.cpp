/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <fstream>
#include "Engine.h"

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
        std::string output;
        Json::StyledWriter writer;
        output=writer.write(record);
        std::fstream fichier("./enregistrement",ios::in|ios::app);
        if(fichier){
            fichier << output << std::endl;
            fichier.close();
        }
        return actions;
    }
}
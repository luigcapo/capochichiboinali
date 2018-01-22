/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>

#include "RandomAI.h"
#include "engine/Engine.h"
using namespace state;
using namespace engine;

namespace ai{


    RandomAI::RandomAI() { }
    
    void RandomAI::stateChanged(const state::Event& event) {
        
    }

    void RandomAI::run(engine::Engine& engine) {
        std::vector<Command*> list;
        
        for(size_t i=0;i<engine.getState().getTerrain().getWidth();i++){
            for(size_t j=0;j<engine.getState().getTerrain().getHeight();j++){
                auto c=clock();
                auto cc=clock();
                int randomSeed=c;
                int randoomSeed=cc;
                if(engine.getState().getChars().get(i,j)){
                    listCommands(list, engine.getState().getChars().get(i,j));
                    engine.addCommand(list[randomSeed % list.size()]);
                    list.clear();
                }
                if(engine.getState().getGrid().get(i,j)){
                    if(engine.getState().getGrid().get(i,j)->getTypeId()==4){
                        if(engine.getState().getNumber()<20){
                            listCommands(list, engine.getState().getGrid().get(i,j));
                            engine.addCommand(list[randoomSeed % list.size()]);
                            list.clear();
                        }
                    }
                }
                engine.update();
                
            }
        }
    }
    void RandomAI::runClient(engine::EngineClient& engine) {
        std::vector<Command*> list;
        
        for(size_t i=0;i<engine.getState().getTerrain().getWidth();i++){
            for(size_t j=0;j<engine.getState().getTerrain().getHeight();j++){
                auto c=clock();
                auto cc=clock();
                int randomSeed=c;
                int randoomSeed=cc;
                if(engine.getState().getChars().get(i,j)){
                    listCommands(list, engine.getState().getChars().get(i,j));
                    engine.addCommand(list[randomSeed % list.size()]);
                    list.clear();
                }
                if(engine.getState().getGrid().get(i,j)){
                    if(engine.getState().getGrid().get(i,j)->getTypeId()==4){
                        if(engine.getState().getNumber()<20){
                            listCommands(list, engine.getState().getGrid().get(i,j));
                            engine.addCommand(list[randoomSeed % list.size()]);
                            list.clear();
                        }
                    }
                }
                engine.update();
                
            }
        }
    }

    
    void RandomAI::runReplay(engine::Engine& engine) {
        std::vector<Command*> list;
        auto c=clock();
        int randomSeed=c;
        for(size_t i=0;i<engine.getState().getChars().getWidth();i++){
            for(size_t j=0;j<engine.getState().getChars().getHeight();j++){
                if(engine.getState().getChars().get(i,j)){
                    listCommands(list, engine.getState().getChars().get(i,j));
                    engine.addCommand(list[randomSeed % list.size()]);
                    engine.updateReplay();
                    list.clear();
                }
            }
        }
    }

}


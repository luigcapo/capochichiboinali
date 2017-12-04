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

    void RandomAI::run(engine::Engine& engine) {
        std::vector<Command*> list;
        for(size_t i=1;i<engine.getState().getChars().getWidth()-1;i++){
            for(size_t j=1;j<engine.getState().getChars().getHeight()-1;j++){
                if(engine.getState().getChars().get(i,j)){
                    listCommands(list, engine.getState().getChars().get(i,j));
                    engine.addCommand(list[randgen() % list.size()]);
                    engine.update();
                    
                    //std::cout<<"euh"<<std::endl;
                    for(size_t h=1;h<list.size();h++){
                    std::cout<<"euh"<<std::endl;
                        delete(list[h]);
                    }
                    list.clear();
                }
                
            }
        }
        
    }

}


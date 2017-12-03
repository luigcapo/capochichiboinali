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
        //list.resize(200);
        std::cout<<list.size()<<std::endl;
        //list.resize(100);
        listCommands(list, engine.getState());
        std::cout<<list.size()<<std::endl;
        engine.addCommand(list[randgen() % list.size()]);
        engine.update();
        list.clear();
    }

}

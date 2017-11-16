/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "RandomAI.h"
#include "engine/Engine.h"
using namespace state;
using namespace engine;

namespace ai{


    RandomAI::RandomAI() { }

    void RandomAI::run(engine::Engine& engine) {
        std::vector<Command*> list;
        listCommands(engine.getState(),list);
        engine.execute(list[randgen() % list.size()]);
    }

}

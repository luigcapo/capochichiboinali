/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>

#include "CreateCombatCommand.h"
#include "state/MilTypeId.h"
#include "state/Military.h"
#include "state/Batiment.h"

using namespace state;

namespace engine {

    CreateCombatCommand::CreateCombatCommand(state::MilTypeId m,int x, int y):unit(0), x(x), y(y){
        unit = new Military(m);
    }

    CreateCombatCommand::~CreateCombatCommand() {
        delete unit;
    }
    bool CreateCombatCommand::tryCreateChars(state::State& state) const{
        std::cout<<state.getGrid().get(x,y)->getTypeId()<<std::endl;
        if(state.getGrid().get(x,y)){
            if(state.getGrid().get(x,y)->getTypeId()== 4){
                Batiment* b=(Batiment*) state.getGrid().get(x,y);
                if(b->getBatimentTypeId()== 6){
                    if(state.getChars().get(x,y)){return false;}
                    else{
                        return true;
                    }
                }
                else{return false;}
            }
            else{ return false;}
        }
        else{return false;}
    }

    void CreateCombatCommand::execute(state::State& state, std::stack<Action*>& s) {
        if (tryCreateChars(state)){
            state.getChars().set(x,y,unit);
            unit->setJ(state.getGrid().get(x,y)->getJ());
            unit->setCombat(100);
            unit->setPv(30);
        }
        else{}
            
    }

    CommandTypeId CreateCombatCommand::getTypeId() const {
        return CommandTypeId::CREATE;
    }

    void CreateCombatCommand::serialized(Json::Value& out) const {

    }


}

    
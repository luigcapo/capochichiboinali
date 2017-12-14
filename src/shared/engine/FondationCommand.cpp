/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "FondationCommand.h"
#include "state/Colon.h"
using namespace state;

namespace engine {

    void FondationCommand::fonda(state::Colon*c) {
        state::Colonie co= state::Colonie();
        delete(c);
        c=0;
    }

    CommandTypeId FondationCommand::getTypeId() const {
        return CommandTypeId::FONDA;
    }

    void FondationCommand::execute(state::State& state,std::stack<Action*>& s) {
        for(std::size_t i=0; i< state.getChars().getHeight(); i++){
            for(std::size_t j=0; j< state.getChars().getWidth(); j++){
                if(state.getChars().get(i,j)->getTypeId()!=1){}
                else{
                    Colon*c= (Colon*) state.getChars().get(i,j);
                    fonda(c);
                }
            }
                
            }
    }
    void FondationCommand::serialized(Json::Value& out) const {

    }



    
}
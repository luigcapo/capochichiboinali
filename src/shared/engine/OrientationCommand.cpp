/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "OrientationCommand.h"

namespace engine{

    OrientationCommand::OrientationCommand(int c, state::Direction d) {

    }

    void OrientationCommand::execute(state::State& state) {

    }

    int OrientationCommand::getCharacter() const {

    }

    void OrientationCommand::setCharacter(int character) {

    }

    
    /*void MoveCommand::execute(state::State& state) {
        state::ElementTab listt=state.getChars();
        for(int i=0;i<listt.getHeight();i++){
            for(int j=0;i<listt.getWidth();i++){
                state::Element e=listt.get(i,j);
                if(e.isStatic()==true){}
                else{
                    
                }
            }
            
        }    
    }*/
    CommandTypeId OrientationCommand::getTypeId() const {
        return CommandTypeId::ORIENTATION; 
    } 
}

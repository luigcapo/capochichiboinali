/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "OrientationCommand.h"

namespace engine{

    int OrientationCommand::OrientatonCommand(int c, state::Direction d) {
        
    }

    int OrientationCommand::execute(state::State& state) {

    }

    int OrientationCommand::getCharacter() const {
        
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
        return CommandTypeId.ORIENTATION; 
    } 
}
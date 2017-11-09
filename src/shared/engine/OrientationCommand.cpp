/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "OrientationCommand.h"

namespace engine{

    OrientationCommand::OrientationCommand(int c, state::Direction d) {
        this->character=c;
        this->orientation=d;
    }

    void OrientationCommand::execute(state::State& state) {
        state::ElementTab listt=state.getChars();
        for(unsigned int i=0;i<listt.getHeight();i++){
            for(unsigned 
                    int j=0;i<listt.getWidth();i++){
                state::Element* e=listt.get(i,j);
                if(e->getTypeId()!= character){}
                else{  
                    if(e->isStatic()==true){}
                    else{
                        if (orientation==state::Direction::NORTH){e->setY(e->getY()+1);}
                        else if(orientation==state::Direction::NORTH_EAST){e->setX(e->getX()+1);e->setY(e->getY()+1);}
                        else if(orientation==state::Direction::NORTH_WEST){e->setX(e->getX()-1);e->setY(e->getY()+1);}
                        else if(orientation==state::Direction::SOUTH){e->setY(e->getY()-1);}
                        else if(orientation==state::Direction::SOUTH_EAST){e->setX(e->getX()+1);e->setY(e->getY()-1);}
                        else if(orientation==state::Direction::SOUTH_WEST){e->setX(e->getX()-1);e->setY(e->getY()-1);}
                        else if(orientation==state::Direction::EAST){e->setX(e->getX()+1);}
                        else if(orientation==state::Direction::WEST){e->setX(e->getX()-1);}
                        else{}    
                    }
                }
                
            }    
        }

    }

    int OrientationCommand::getCharacter() const {
        return character;
    }

    void OrientationCommand::setCharacter(int character) {
        this->character=character;
    }

    state::Direction OrientationCommand::getOrientation() const {
        return orientation;
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

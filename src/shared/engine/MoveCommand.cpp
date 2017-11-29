/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>

#include "MoveCommand.h"
#include "state/Terrain.h"

using namespace state;
using namespace std;

//Le lien entre la direction et le nombre de déplacement sera rajouté ultérieurement
namespace engine {

    MoveCommand::MoveCommand(int x, int y, int x1, int y1) : x(x), y(y), x1(x1), y1(y1) {
    }

    bool MoveCommand::trymove(state::State& state) const {
        Terrain* p;
        if (state.getChars().get(x1,y1)){return 0;}//A mettre ou pas lorsque j'aurai une vrai map.
        else if(state.getGrid().get(x1,y1)){
            if (state.getChars().get(x, y)->getJ() != state.getGrid().get(x1, y1)->getJ()) {
                return 0;
            }
        }
        else{
            if (state.getChars().get(x, y)->getJ() != state.getTerrain().get(x1, y1)->getJ()) {
                return 1;
            }else if (state.getTerrain().get(x1, y1)) {
            p = (Terrain*) state.getTerrain().get(x1, y1);
            if (p->getTerrainTypeId() == state::OCEAN) {
                return 0;
            } else {
                return 1;
            }
        } else {
            return 1;
        }
    }
}

    void MoveCommand::execute(state::State& state) {
        if (trymove(state)) {
            state.getChars().set(x1, y1, state.getChars().release(x, y));
        } else {
            std::cout << "impossible de déplacer l'élément" << std::endl;
        }
    }

    CommandTypeId MoveCommand::getTypeId() const {
        return CommandTypeId::MOVE;
    }


    /*
    void OrientationCommand::execute(state::State& state) {
        //state::ElementTab listt= state.getChars();
        for(std::size_t i=0; i< state.getChars().getHeight(); i++){
            for(std::size_t j=0; j< state.getChars().getWidth(); j++){
                state::Element* e = state.getChars().get(i,j);
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

    CommandTypeId OrientationCommand::getTypeId() const {
        return CommandTypeId::ORIENTATION; 
    }
     */
}

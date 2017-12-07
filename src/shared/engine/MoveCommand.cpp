/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>

#include "MoveCommand.h"
#include "state/Terrain.h"
#include "MoveAction.h"

using namespace state;
using namespace std;

//Le lien entre la direction et le nombre de déplacement sera rajouté ultérieurement
namespace engine {


    MoveCommand::MoveCommand(int x, int y, int x1, int y1) : x(x), y(y), x1(x1), y1(y1) {
    }

    bool MoveCommand::trymove(state::State& state) const {
        Terrain* p;
        if (state.getChars().get(x1,y1)){return 0;}//A mettre ou pas lorsque j'aurai une vrai map.
        else if(state.getGrid().get(x1,y1) && !(state.getChars().get(x1,y1))){
            if (state.getChars().get(x, y)->getJ() != state.getGrid().get(x1, y1)->getJ()) {
                return 0;
            }
            return 1;
            
        }
        else{
            if (state.getChars().get(x, y)->getJ() != state.getTerrain().get(x1, y1)->getJ()) {
                return 1;
            }
            else if (state.getTerrain().get(x1, y1)) {
                p = (Terrain*) state.getTerrain().get(x1, y1);
                if (p->getTerrainTypeId() == state::OCEAN) {
                    return 0;
                } else {
                    return 1;
                }
            } 
            else {return 1;}   
        }
    }
    /*
    void MoveCommand::execute(state::State& state,std::stack<Action*>& s) {
        if (trymove(state)) {
            state.getChars().set(x1, y1, state.getChars().release(x, y));
        } else {
            std::cout << "impossible de déplacer l'élément" << std::endl;
        }
    }
    */
    void MoveCommand::execute(state::State& state,std::stack<Action*>& s) {
        if (trymove(state)) {
            MoveAction *mov=new MoveAction(x,y,x1,y1);
            mov->apply(state);
            s.push(mov);
            //state.getChars().set(x1, y1, state.getChars().release(x, y));
        } else {
            std::cout << "impossible de déplacer l'élément" << std::endl;
        }
    }

    CommandTypeId MoveCommand::getTypeId() const {
        return CommandTypeId::MOVE;
    }
}



/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "AI.h"
#include "engine/FondationCommand.h"
#include "engine/MoveCommand.h"
#include "engine/AttaqueCommand.h"
using namespace state;
using namespace engine;

namespace ai{

    void AI::listCommands (std::vector<engine::Command*> list, state::State& state) {
        for(unsigned int i=0;i<state.getChars().getWidth();i++){
            for(unsigned int j=0;j<state.getChars().getHeight();j++){
                if(state.getChars().get(i,j)->getTypeId()==1){
                    list.push_back(new FondationCommand());
                    list.push_back(new MoveCommand(i,j,i+1,j+1));
                    list.push_back(new MoveCommand(i,j,i,j+1));
                    list.push_back(new MoveCommand(i,j,i-1,j+1));
                    list.push_back(new MoveCommand(i,j,i+1,j));
                    list.push_back(new MoveCommand(i,j,i-1,j));
                    list.push_back(new MoveCommand(i,j,i+1,j-1));
                    list.push_back(new MoveCommand(i,j,i,j-1));
                    list.push_back(new MoveCommand(i,j,i-1,j-1));
                }
                else if(state.getChars().get(i,j)->getTypeId()==2){
                    list.push_back(new MoveCommand(i,j,i+1,j+1));
                    list.push_back(new MoveCommand(i,j,i,j+1));
                    list.push_back(new MoveCommand(i,j,i-1,j+1));
                    list.push_back(new MoveCommand(i,j,i+1,j));
                    list.push_back(new MoveCommand(i,j,i-1,j));
                    list.push_back(new MoveCommand(i,j,i+1,j-1));
                    list.push_back(new MoveCommand(i,j,i,j-1));
                    list.push_back(new MoveCommand(i,j,i-1,j-1));
                    list.push_back(new AttaqueCommand(i,j,i+1,j+1));
                    list.push_back(new AttaqueCommand(i,j,i,j+1));
                    list.push_back(new AttaqueCommand(i,j,i-1,j+1));
                    list.push_back(new AttaqueCommand(i,j,i+1,j));
                    list.push_back(new AttaqueCommand(i,j,i-1,j));
                    list.push_back(new AttaqueCommand(i,j,i+1,j-1));
                    list.push_back(new AttaqueCommand(i,j,i,j-1));
                    list.push_back(new AttaqueCommand(i,j,i-1,j-1));
                }
                else{}
            }
        }
        
    }
}


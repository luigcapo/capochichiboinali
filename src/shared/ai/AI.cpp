/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>

#include "AI.h"
#include "engine/FondationCommand.h"
#include "engine/MoveCommand.h"
#include "engine/AttaqueCommand.h"
using namespace state;
using namespace engine;

namespace ai{

    void AI::listCommands(std::vector<engine::Command*>& list, state::Element* e) {
                    int i,j;
                    i=e->getX();
                    j=e->getY();        
                    if(e->getTypeId()==1){
                        //list.push_back(new FondationCommand());
                        list.push_back(new MoveCommand(i,j,i+1,j+1));
                        list.push_back(new MoveCommand(i,j,i,j+1));
                        list.push_back(new MoveCommand(i,j,i-1,j+1));
                        list.push_back(new MoveCommand(i,j,i+1,j));
                        list.push_back(new MoveCommand(i,j,i-1,j));                   
                        list.push_back(new MoveCommand(i,j,i+1,j-1));
                        list.push_back(new MoveCommand(i,j,i,j-1));
                        list.push_back(new MoveCommand(i,j,i-1,j-1));
                    }
                    else if(e->getTypeId()==2){
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


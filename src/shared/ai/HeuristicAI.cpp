/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "HeuristicAI.h"
#include "state.h"
#include "engine.h"
#include "Point.h"
#include <iostream>

namespace ai{
    
    HeuristicAI::HeuristicAI (state::State& state) {
        this->batJoueur1Map.init(state);
        this->batJoueur2Map.init(state);
        this->unitJoueur1Map.init(state);
        this->unitJoueur2Map.init(state);
        
        /*
         * 
         * 1. On ajoute des puits aux endroits qui
         * nous intéressent sur les différents maps
         * 
         */
        for(std::size_t i=0; i<state.getGrid().getWidth(); i++){
            for(std::size_t j=0; j<state.getGrid().getHeight(); j++){
                if(state.getGrid().get(i, j)){
                    if(state.getGrid().get(i, j)->getTypeId() == state::TypeId::BATIMENT){
                        if(state.getGrid().get(i, j)->getJ() == 0){
                            this->batJoueur1Map.addSink(Point(i, j, 0));
                        }
                        else if(state.getGrid().get(i, j)->getJ() == 1){
                            this->batJoueur2Map.addSink(Point(i, j, 0));
                        }
                    }
                }
                if(state.getChars().get(i, j)){
                    // on teste si joueur 1
                    if(state.getChars().get(i, j)->getJ() == 0){
                        this->unitJoueur1Map.addSink(Point(i, j, 0));
                    }
                    // on teste si joueur 2
                    if(state.getChars().get(i, j)->getJ() == 1){
                        this->unitJoueur2Map.addSink(Point(i, j, 0));
                    }
                }
            }
        }
        this->batJoueur1Map.update(state);
        this->batJoueur2Map.update(state);
        this->unitJoueur1Map.update(state);
        this->unitJoueur2Map.update(state);
    }
    
    const PathMap& HeuristicAI::getBatJoueur1Map() const {
        return this->batJoueur1Map;
    }

    const PathMap& HeuristicAI::getBatJoueur2Map() const {
        return this->batJoueur2Map;
    }

    const PathMap& HeuristicAI::getUnitJoueur1Map() const {
        return this->unitJoueur1Map;
    }

    const PathMap& HeuristicAI::getUnitJoueur2Map() const {
        return this->unitJoueur2Map;
    }
    
    void HeuristicAI::stateChanged(const state::Event& event) {
        //int xx=event->x;
        //int yy=event->y;
        
    }

    void HeuristicAI::run(engine::Engine& engine) { 
        /*
         * 
         * 2. Heuristic_ai
         * 
         * Les unités du joueur 2 vont se déplacer alétoirement si elles ne
         * sont pas attaquées sinon elles se défendent en attaquant à leur tour
         * 
         * Les unités du joueur 1 vont se rapprocher de l'ennemi le plus
         * proche afin de l'éliminer
         *  
         */
        for(std::size_t i=0; i<engine.getState().getChars().getWidth(); i++){
            for(std::size_t j=0; j<engine.getState().getChars().getHeight(); j++){
                if(engine.getState().getChars().get(i, j)){
                    // on teste si joueur 2
                    if(engine.getState().getChars().get(i, j)->getJ() == 1){
                        /*int xy;
                        //Point p1(i, j, 0);
                        switch(xy){
                            case 0:
                                break;
                            case 1:
                                break;
                            case 2:
                                break;
                            case 3:
                                break;
                            default:
                                break;
                        }*/
                    }

                    // on teste si joueur  1 (par défaut)
                    if(engine.getState().getChars().get(i, j)->getJ() == 0){
                        // pour se rapprocher des unités ennemies
                        Point pp1 = unitJoueur2Map.getWeightMin(i,j);
                        //MoveCommmand(pp)
                        if(engine.getState().getChars().get(pp1.getX(), pp1.getY())){
                            if(engine.getState().getChars().get(pp1.getX(), pp1.getY())->getJ() == 1){
                                engine.addCommand(new engine::AttaqueCommand(i, j, pp1.getX(), pp1.getY()));
                            }
                            else{engine.addCommand(new engine::MoveCommand(i, j, pp1.getX(), pp1.getY()));}
                        }
                        
                    }
                }
            }
        }
        engine.update();
        
    }// Heuristic_ai
    
}
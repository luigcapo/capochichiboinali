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
    
    HeuristicAI::HeuristicAI (const state::State& state) {
        /*this->batJoueur1Map.init(state.getTerrain());
        this->batJoueur2Map.init(state.getTerrain());
        this->unitJoueur1Map.init(state.getTerrain());
        this->unitJoueur2Map.init(state.getTerrain());*/
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

    void HeuristicAI::run(engine::Engine& engine) {
        
        /*
         * 
         * 1. On ajoute des puits aux endroits qui
         * nous intéressent sur les différents maps
         * 
         */
        // unitJoueur1Map et unitJoueur2Map
        /*for(int i=0; i<engine.getState().getChars().getWidth(); i++){
            for(int j=0; j<engine.getState().getChars().getHeight(); j++){
                if(engine.getState().getChars().get(i, j)){
                    // on teste si joueur 1
                    if(engine.getState().getChars().get(i, j)->getJ() == 0){
                        this->unitJoueur1Map.addSink(Point(i, j, 0));
                    }
                    // on teste si joueur 2
                    if(engine.getState().getChars().get(i, j)->getJ() == 1){
                        this->unitJoueur2Map.addSink(Point(i, j, 0));
                    }
                }
            }
        }
        this->unitJoueur1Map.update(engine.getState().getTerrain());
        this->unitJoueur2Map.update(engine.getState().getTerrain());
        // batJoueur1Map et batJoueur2Map
        for(int i=0; i<engine.getState().getGrid().getWidth(); i++){
            for(int j=0; j<engine.getState().getGrid().getHeight(); j++){
                if(engine.getState().getGrid().get(i, j)){
                    if(engine.getState().getGrid().get(i, j)->getTypeId() == state::Batiment){
                        if(engine.getState().getGrid().get(i, j)->getJ() == 0){
                            this->batJoueur1Map.addSink(Point(i, j, 0));
                        }
                        else if(engine.getState().getGrid().get(i, j)->getJ() == 1){
                            this->batJoueur2Map.addSink(Point(i, j, 0));
                        }
                    }
                }
            }
        }
        this->batJoueur1Map.update(engine.getState().getTerrain());
        this->batJoueur2Map.update(engine.getState().getTerrain());
        */
        /*
         * 
         * 2. Partie 1 Heuristic_ai
         * Les unités du joueur 2 vont se déplacer alétoirement si elles ne
         * sont pas attaquées sinon elles se défendent en attaquant à leur tour
         *  
         */
        /*for(int i=0; i<engine.getState().getChars().getWidth(); i++){
            for(int j=0; j<engine.getState().getChars().getHeight(); j++){
                if(engine.getState().getChars().get(i, j)){
                    // on teste si joueur 2
                    if(engine.getState().getChars().get(i, j)->getJ() == 1){
                        int xy;
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
                        }
                    }
                    
                    
                    
                    // on teste si joueur  1 (par défaut)
                    if(engine.getState().getChars().get(i, j)->getJ() == 0){
                        // pour se rapprocher des unités ennemies
                        Point pp1(i, j, 0);
                        Point pp2(i, j, 0);
                        if(unitJoueur1Map.getWeight(pp1) < unitJoueur1Map.getWeight(pp2){  
                                
                        }
                    }
                }
            }
        }*/
        
        /*
         * 
         * 3. Partie 2 Heuristic_ai
         * Les unités du joueur 1 vont se rapprocher de l'ennemi le plus
         * proche afin de l'éliminer
         *  
         */
        
    }   // Heuristic_ai
    
}
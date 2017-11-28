/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "TestAI.h"
#include "state.h"
#include "ai.h"
#include "engine.h"

using namespace std;
using namespace state;
using namespace engine;

namespace ai{
    
    void testRandomAI(){
        std::cout<< "Epoque 1"<<std::endl;
        State state;
        std::cout<< "Ajout de deux joueurs à notre état"<<std::endl;
        state.addJoueur(new Joueur(1));
        state.addJoueur(new Joueur(2));
        state.getChars().resize(10,10);
        state.getTerrain().resize(10,10);
        std::cout<< state.getChars().getHeight()<< "et"<<state.getChars().getWidth()<<std::endl;
        for (int i=0;i<9;i++){
            for (int j=0;j<9;j++){
                Colon*e=new Colon();
                state.getChars().set(i,j,e);
            }
        }
        for (int i=0;i<9;i++){
            for (int j=0;j<9;j++){
                Terrain*p=new Terrain(PLAINE);
                state.getTerrain().set(i,j,p);
            }
        }
        
        std::cout<< "debugger perso"<<std::endl;
        std::cout<<state.getChars().get(0,0)->getTypeId()<<std::endl;
        engine::Engine*eng = new Engine(state);
        RandomAI randoom;
        randoom.run(*eng);
        std::cout<< "ca marche" << std::endl;
    }
    
}
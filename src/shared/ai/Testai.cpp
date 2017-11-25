/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Testai.h"
#include "state/State.h"
#include "RandomAI.h"
#include "state/Military.h"
#include "engine/Engine.h"

using namespace std;
using namespace state;
using namespace engine;

namespace ai{
    void testai(){
        std::cout<< "Epoque 1"<<std::endl;
        State state;
        std::cout<< "Ajout de deux joueurs à notre état"<<std::endl;
        state.addJoueur(new Joueur(1));
        state.addJoueur(new Joueur(2));
        state.getChars().resize(100,100);
        for (int i=0;i<100;i++){
            for (int j=0;j<100;j++){
                state::Military*e=new Military(EPEISTE);
                state.getChars().set(i,j,e);
            }
        }
        std::cout<< "debugger perso"<<std::endl;
        engine::Engine*eng = new Engine(state);
        RandomAI randoom;
        randoom.run(*eng);
        std::cout<< "ca marche" << std::endl;
    }
}
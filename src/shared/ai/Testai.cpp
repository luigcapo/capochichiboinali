/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Testai.h"
#include "state/State.h"
#include "RandomAI.h"

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
        for (int i=0;i<100;i++){
            for (int j=0;j<100;j++){
                Millitary e;
                state.getChars().set(i,j,e);
            }
        }
        Engine*eng = new Engine(state);
        RandomAI randoom;
        randoom.run(eng);
        std::cout<< "ca marche" << std::endl;
    }
}
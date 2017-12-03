/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "TestAI.h"
#include "state.h"
#include "render.h"
#include <SFML/Graphics.hpp>
#include "ai.h"
#include "engine.h"
#include <memory>
#include <string>


using namespace std;
using namespace state;
using namespace engine;
using namespace render;

namespace ai{
    
    void testRandomAI(){
        sf::RenderWindow window(sf::VideoMode(1920, 1056),"Test Engine");
        std::cout<<"Touches"<<std::endl;
        std::cout<<"  <espace>:passer à l'époque suivante"<<std::endl;
        State state;
        state.addJoueur(new Joueur(1));
        state.addJoueur(new Joueur(2));
        state.getChars().resize(100,100);
        Military *m=new Military(MOUSQUETAIRE);
        Military *m1=new Military(EPEISTE);
        Colon *c = new Colon();
        Military *m2= new Military(MOUSQUETAIRE);
        m->setJ(1);
        m1->setJ(1);
        m->setCombat(60);
        m1->setCombat(60);
        m2->setCombat(60);
        m2->setJ(2);
        c->setJ(1);
        engine::Engine*eng = new Engine(state);
        RandomAI randoom;
        eng->addCommand(new LoadCommand("res/mapEngine.csv", "res/mapEngine_Grid.csv"));
        eng->update();
        state.getChars().set(2,9,m2);
        state.getChars().set(10,10,m1);
        eng->getState().getChars().set(3,5,m);
        render::ElementTabLayer tMap(eng->getState().getTerrain(), 1);
        tMap.initSurface();
        render::ElementTabLayer tGrid(eng->getState().getGrid(), 2);
        tGrid.initSurface();    
        render::ElementTabLayer tChars(eng->getState().getChars(), 3);
        tChars.initSurface();
        while (window.isOpen()){
            sf::Event event;
            
            while (window.pollEvent(event)){
                if (event.type == sf::Event::KeyPressed){
                
                    if (event.key.code == sf::Keyboard::Space){
                        randoom.run(*eng);
                    }
                }
            }
            render::ElementTabLayer tMap(eng->getState().getTerrain(), 1);
            tMap.initSurface();
            render::ElementTabLayer tGrid(eng->getState().getGrid(), 2);
            tGrid.initSurface();    
            render::ElementTabLayer tChars(eng->getState().getChars(), 3);
            tChars.initSurface();
            window.clear();
            window.draw(*(tMap.getSurface()));
            window.draw(*(tGrid.getSurface()));
            window.draw(*(tChars.getSurface()));
            window.display();
                
            } 
          
        /*
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
        */
    }
    
}
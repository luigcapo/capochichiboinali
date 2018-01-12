/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Client.h"
#include <iostream>
#include "state.h"
#include "engine.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include <SFML/Window/../System/Time.hpp>
#include <thread>
#include "unistd.h"

using namespace std;
using namespace state;
using namespace engine;
using namespace render;
using namespace ai;

namespace client {

    Client::Client() {
        
    }

    void Client::engineUpated() {
        
    }

    void Client::engineUpdating() {
        
    }

    void Client::run() {
        sf::RenderWindow window(sf::VideoMode(768, 768),"Client");
        
        /* On crée notre état */
        State state;
        state.getChars().resize(17,17);
        
        /* On ajoute 2 joueurs */
        state.addJoueur(new Joueur(1));
        state.addJoueur(new Joueur(2));
        
        Military *m=new Military(MOUSQUETAIRE);
        Military *m1=new Military(EPEISTE);
        Colon *c1 = new Colon();
        Colon *c2 = new Colon();
        Military *m2= new Military(MOUSQUETAIRE);
        m->setJ(1);
        m1->setJ(1);
        m->setCombat(60);
        m1->setCombat(60);
        m2->setCombat(60);
        m2->setJ(2);
        c1->setJ(1);
        c2->setJ(2);
        state.getChars().set(2,9,m2);
        state.getChars().set(3,8,m1);
        state.getChars().set(3,5,m);
        state.getChars().set(10,3,c1);
        state.getChars().set(15,4,c2);
        
        /* On crée une IA aléatoire */
        AI *random;
        random = new RandomAI();
        
        /* On crée notre moteur de jeu */
        engine::Engine *eng = new Engine(state);
        eng->addCommand(new LoadCommand("res/mapEngine.csv", "res/mapEngine_Grid.csv"));
        eng->update();  // On charge la map

        /* On crée et on lance le thread secondaire pour le moteur de jeu */
        thread th(&Engine::runThread, eng, random);
        
        /* Configuration du rendu */
        render::TerrainLayer tMap(eng->getState().getTerrain());
        tMap.initSurface();
        render::GridLayer tGrid(eng->getState().getGrid());
        tGrid.initSurface();
        render::CharsLayer tChars(eng->getState().getChars());
        tChars.initSurface();
        
        std::cout << "Touches :" << std::endl;
        std::cout << "    <espace> : passer à l'époque suivante" << std::endl;
        
        while (window.isOpen()){
            sf::Event event;
            while (window.pollEvent(event)){
                if (event.type == sf::Event::Closed){
                    window.close();
                }
                else if (event.key.code == sf::Keyboard::Space){
                    eng->setRun_randomAI(true);
                }
            }
                render::TerrainLayer tMap(eng->getState().getTerrain());
                tMap.initSurface();
                render::GridLayer tGrid(eng->getState().getGrid());
                tGrid.initSurface();
                render::CharsLayer tChars(eng->getState().getChars());
                tChars.initSurface();
                window.clear();
                window.draw(*(tMap.getSurface()));
                window.draw(*(tGrid.getSurface()));
                window.draw(*(tChars.getSurface()));
                window.display();
        }
        
        th.join();
    }

}
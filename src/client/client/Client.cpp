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

using namespace std;
using namespace state;
using namespace engine;
using namespace render;
using namespace ai;

namespace client {

    Client::Client() {
        // On charge la map
        /*engine.addCommand(new engine::LoadCommand("res/mapEngine.csv", "res/mapEngine_Grid.csv"));
        engine.update();
        
        // On ajoute 2 joueurs à l'état
        engine.getState().addJoueur(new Joueur(1));
        engine.getState().addJoueur(new Joueur(2));
        
        // On redimensionne la liste des personnnages pour correspondre à la taille de la map
        engine.getState().getChars().resize(30,30);
        
        // Création des unités
        Military *m11=new Military(MOUSQUETAIRE);
        Military *m12=new Military(EPEISTE);
        Military *m21= new Military(MITRAILLEUR);
        Military *m22= new Military(MOUSQUETAIRE);
        Colon *c1 = new Colon();
        Colon *c2 = new Colon();
        
        // On fixe les propriétés des unités
        c1->setJ(1);
        c1->setDirection(state::Direction::EAST);
        c2->setJ(2);
        m11->setJ(1);
        m11->setDirection(state::Direction::SOUTH);
        m12->setJ(1);
        m21->setJ(2);
        m21->setDirection(state::Direction::NORTH_EAST);
        m22->setJ(2);
        m11->setCombat(50);
        m12->setCombat(60);
        m21->setCombat(60);
        m22->setCombat(50);
        
        // Ajout des unités à l'état
        engine.getState().getChars().set(2,8,c1);
        engine.getState().getChars().set(15,9,m11);
        engine.getState().getChars().set(19,7,m12);
        engine.getState().getChars().set(15,1,c2);
        engine.getState().getChars().set(10,3,m21);
        engine.getState().getChars().set(3,5,m22);*/
    }

    void Client::engineUpated() {
        
    }

    void Client::engineUpdating() {
        
    }

    void Client::run() {
        sf::RenderWindow window(sf::VideoMode(1920, 1056),"Test Thread");
        
        /*render::TerrainLayer tMap(engine.getState().getTerrain());
        render::GridLayer tGrid(engine.getState().getGrid());
        render::CharsLayer tChars(engine.getState().getChars());
        tMap.initSurface();
        tGrid.initSurface();
        tChars.initSurface();
        
        // Création thread pour le moteur du jeu
        //thread th();
        
        sf::Clock clock;
        //float time = 1.f;
        
        while (window.isOpen()){
            sf::Event event;
            //sf::Time time_elapsed = clock.getElapsedTime();
            float x = clock.getElapsedTime().asSeconds();
            //cout << x << endl;
            while (window.pollEvent(event)){
                if (x>1.f){
                    clock.restart();
                    random.run(engine);
                    //tChars.initSurface();
                    //time+=1.f;
                    
                }
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            render::TerrainLayer tMap(engine.getState().getTerrain());
            tMap.initSurface();
            render::GridLayer tGrid(engine.getState().getGrid());
            tGrid.initSurface();
            render::CharsLayer tChars(engine.getState().getChars());
            tChars.initSurface();
            window.clear();
            window.draw(*(tMap.getSurface()));
            window.draw(*(tGrid.getSurface()));
            window.draw(*(tChars.getSurface()));
            window.display();
        }*/
        
    }

}
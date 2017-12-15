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
#include <SFML/Window/../System/Time.hpp>
#include <thread>
#include "unistd.h"

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
        state.getChars().set(5.3,8.1,m1);
        eng->getState().getChars().set(3,5,m);
        render::TerrainLayer tMap(eng->getState().getTerrain());
        tMap.initSurface();
        render::GridLayer tGrid(eng->getState().getGrid());
        tGrid.initSurface();    
        render::CharsLayer tChars(eng->getState().getChars());
        tChars.initSurface();
        while (window.isOpen()){
            sf::Event event;
            
            while (window.pollEvent(event)){
                if (event.type == sf::Event::KeyPressed){
                
                    if (event.key.code == sf::Keyboard::Space){
                        randoom.run(*eng);
                    }
                }
                if (event.type == sf::Event::Closed)
                        window.close();
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
    }
    
    void testThread2(){
        sf::RenderWindow window(sf::VideoMode(1920, 1056),"Test Thread");
        State state;
        // On ajoute 2 joueurs
        state.addJoueur(new Joueur(1));
        state.addJoueur(new Joueur(2));
        
        state.getChars().resize(20,11);
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
        state.getChars().set(5.3,8.1,m1);
        state.getChars().set(3,5,m);
        
        engine::Engine *eng = new Engine(state);
        RandomAI random;
        eng->addCommand(new LoadCommand("res/mapEngine.csv", "res/mapEngine_Grid.csv"));
        eng->update();
        
        render::TerrainLayer tMap(eng->getState().getTerrain());
        tMap.initSurface();
        render::GridLayer tGrid(eng->getState().getGrid());
        tGrid.initSurface();    
        render::CharsLayer tChars(eng->getState().getChars());
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
                    random.run(*eng);
                    //tChars.initSurface();
                    //time+=1.f;
                    
                }
                if (event.type == sf::Event::Closed)
                    window.close();
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
    }

    void testThread(){
        sf::RenderWindow window(sf::VideoMode(1920, 1056),"Test Thread");
        State state;
        // On ajoute 2 joueurs
        state.addJoueur(new Joueur(1));
        state.addJoueur(new Joueur(2));
        
        state.getChars().resize(20,11);
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
        
        engine::Engine *eng = new Engine(state);
        eng->addCommand(new LoadCommand("res/mapEngine.csv", "res/mapEngine_Grid.csv"));
        eng->update();
        
        render::TerrainLayer tMap(eng->getState().getTerrain());
        tMap.initSurface();
        render::GridLayer tGrid(eng->getState().getGrid());
        tGrid.initSurface();    
        render::CharsLayer tChars(eng->getState().getChars());
        tChars.initSurface();
        
        // On crée une IA aléatoire
        AI *random;
        random = new RandomAI();
        
        // Création thread pour le moteur du jeu
        thread th(&Engine::runThread, eng, random);
        //sf::Clock clock;
        
        std::cout<<"Touches"<<std::endl;
        std::cout<<"  <espace>:passer à l'époque suivante"<<std::endl;
        
        while (window.isOpen()){
            sf::Event event;
            //float x = clock.getElapsedTime().asSeconds();
            //cout << x << endl;
            while (window.pollEvent(event)){
                if (event.type == sf::Event::Closed){
                    window.close();
                }
                /*else if (x>1.f){
                    eng->setRun_randomAI(true);
                    clock.restart();
                }*/
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
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "TestEngine.h"
#include "state.h"
#include <SFML/Graphics.hpp>
#include "render.h"
#include <memory>
#include <string>

using namespace state;
using namespace engine;
     
void testEngine(){
        
        /*
         * 
         * Epoque 1
         * 
         *
         * 
         */
        sf::RenderWindow window(sf::VideoMode(1920, 1056),"Test Engine");
        int hh = 1;
        std::cout<<"Touches"<<std::endl;
        std::cout<<"  <espace>:passer à l'époque suivante"<<std::endl;
        State etat;
        etat.addJoueur(new Joueur(1));
        etat.addJoueur(new Joueur(2));
        etat.getChars().resize(100,100);
        Military *m=new Military(MOUSQUETAIRE);
        Military *m1=new Military(EPEISTE);
        Colon *c = new Colon();
        Military *m2= new Military(MOUSQUETAIRE);
        //Batiment *b=new Batiment(WATER_MILL);
        //Batiment *bb=new Batiment(WATER_MILL);
        m->setJ(1);
        m1->setJ(1);
        m1->setCombat(60);
        m2->setJ(2);
        c->setJ(1);
        //bb->setJ(1);
        
        //etat.getChars().set(7,7,b);
        //etat.getChars().set(5,4,c);
        //std::cout << "crée le moteur à partir de l'état" << std::endl;
        Engine*eng = new Engine(etat);
        eng->addCommand(new LoadCommand("res/mapEngine.csv", "res/mapEngine_Grid.csv"));
        eng->update();
        etat.getChars().set(2,9,m2);
        etat.getChars().set(10,10,m1);
        eng->getState().getChars().set(3,5,m);
        render::TerrainLayer tMap(eng->getState().getTerrain());
        tMap.initSurface();
        render::GridLayer tGrid(eng->getState().getGrid());
        tGrid.initSurface();    
        render::CharsLayer tChars(eng->getState().getChars());
        tChars.initSurface();
        
        
        while (window.isOpen()){
        sf::Event event;
        // tant qu'il y a des évènements à traiter...
        
        while (window.pollEvent(event)){
            
            if (event.type == sf::Event::KeyPressed){
                
                if (event.key.code == sf::Keyboard::Space){ 
                    if(hh==1){
                        std::cout << " *** Epoque"<<hh<<"***"<< std::endl;
                        std::cout << "crée le moteur à partir de l'état" << std::endl;
                        std::cout << "ajoute de nouvelle commande" << std::endl;
                        eng->addCommand(new MoveCommand(3,5,7,7));
                        eng->update();
                        std::cout<<"Vérifie le déplacement : ";
                        if (etat.getChars().get(7,7)->getTypeId()==2){ std::cout << "OK" << std::endl; }
                        else{ std::cout << "Problème sur la commande" << std::endl; }
                    
                    }
                    
                    else if(hh==2){
                        std::cout << " *** Epoque"<<hh<<"***"<< std::endl;
                        
                        std::cout << "ajoute de nouvelle commande d'attaque" << std::endl;
                        eng->addCommand(new AttaqueCommand(10,10,2,9));
                        eng->update();
                        std::cout <<"Vérifie les points de vie de l'unité attaqué ont diminué:";
                        if (m2->getPv()<100){ std::cout << "OK" << std::endl; }
                        else{ std::cout << "Problème sur la commande" << std::endl; }
                    }
                    else if(hh==3){
                        std::cout << " *** Epoque"<<hh<<"***"<< std::endl;
                        std::cout << "ajoute de nouvelle commande d'attaque" << std::endl;
                        eng->addCommand(new AttaqueCommand(10,10,2,9));
                        eng->update();
                        std::cout <<"Vérifie les points de vie de l'unité attaqué ont diminué:";
                        if (m2->getPv()<40){ std::cout << "OK" << std::endl; }
                        else{ std::cout << "Problème sur la commande" << std::endl; }
                    }
                    
                    hh++;
                    
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
    
    void testRollback(){
        sf::RenderWindow window(sf::VideoMode(1920, 1056),"Test Engine");
        int hh = 1;
        std::cout<<"Touches"<<std::endl;
        std::cout<<"  <espace>:passer à l'époque suivante"<<std::endl;
        State etat;
         std::vector<std::stack <Action*> > actions;
        /*std::stack<Action*> actions;
        std::stack<Action*> actions1;
        std::stack<Action*> actions2;*/
        etat.addJoueur(new Joueur(1));
        etat.addJoueur(new Joueur(2));
        etat.getChars().resize(100,100);
        Military *m=new Military(MOUSQUETAIRE);
        Military *m1=new Military(EPEISTE);
        Colon *c = new Colon();
        Military *m2= new Military(MOUSQUETAIRE);
        //Batiment *b=new Batiment(WATER_MILL);
        //Batiment *bb=new Batiment(WATER_MILL);
        m->setJ(1);
        m1->setJ(1);
        m1->setCombat(60);
        m2->setJ(2);
        c->setJ(1);
        //bb->setJ(1);
        
        //etat.getChars().set(7,7,b);
        //etat.getChars().set(5,4,c);
        Engine*eng = new Engine(etat);
        eng->addCommand(new LoadCommand("res/mapEngine.csv", "res/mapEngine_Grid.csv"));
        eng->update();
        etat.getChars().set(2,9,m2);
        etat.getChars().set(10,10,m1);
        eng->getState().getChars().set(3,5,m);
        render::TerrainLayer tMap(eng->getState().getTerrain());
        tMap.initSurface();
        render::GridLayer tGrid(eng->getState().getGrid());
        tGrid.initSurface();    
        render::CharsLayer tChars(eng->getState().getChars());
        tChars.initSurface();
        
        
        while (window.isOpen()){
        sf::Event event;
        // tant qu'il y a des évènements à traiter...
        
        while (window.pollEvent(event)){
            
            if (event.type == sf::Event::KeyPressed){
                
                if (event.key.code == sf::Keyboard::Space){ 
                    if(hh==1){
                        std::cout << "ajoute de nouvelle commande" << std::endl;
                        eng->addCommand(new MoveCommand(3,5,7,7));
                        actions.push_back(eng->update());
                        //actions=eng->update();
                    }
                    else if(hh==2){
                        std::cout << " *** Epoque"<<hh<<"***"<< std::endl;
                        
                        std::cout << "ajoute de nouvelle commande d'attaque" << std::endl;
                        eng->addCommand(new AttaqueCommand(10,10,2,9));
                        actions.push_back(eng->update());
                    }
                    else if(hh==3){
                        std::cout << " *** Epoque"<<hh<<"***"<< std::endl;
                        std::cout << "ajoute de nouvelle commande d'attaque" << std::endl;
                        eng->addCommand(new AttaqueCommand(10,10,2,9));
                        actions.push_back(eng->update());
                        //actions2=eng->update();
                        if (m2->getPv()<40){ std::cout << "OK" << std::endl; }
                        else{ std::cout << "Problème sur la commande" << std::endl; }
                    }
                    
                    else if(hh==4){
                        std::cout << " *** Epoque"<<hh<<"***"<< std::endl;
                        std::cout << "Inverse toutes les opérations réalisées précédement" << std::endl;
                        eng->undo(actions[2]);
                    }
                    else if(hh==5){
                        std::cout << " *** Epoque"<<hh<<"***"<< std::endl;
                        std::cout << "Inverse toutes les opérations réalisées précédement" << std::endl;
                        eng->undo(actions[1]);
                    }
                    else if(hh==6){
                        std::cout << " *** Epoque"<<hh<<"***"<< std::endl;
                        std::cout << "Inverse toutes les opérations réalisées précédement" << std::endl;
                        eng->undo(actions[0]);
                    }
                    
                    hh++;
                    if(hh>6) hh=1;
                    
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
// fin testEngine
    


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "TestEngine.h"
#include "ai.h"
#include "state.h"
#include <SFML/Graphics.hpp>
#include "render.h"
#include <memory>
#include <string>
#include <fstream>

using namespace state;
using namespace engine;
using namespace ai;
     
void testEngine(){
        
        /*
         Epoque 1
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
        Batiment *bat=new Batiment(GRANARY);
        bat->setJ(1);
        m->setJ(1);
        m1->setJ(1);
        m1->setCombat(60);
        m2->setJ(2);
        c->setJ(1);
        //bb->setJ(1);
        
        //
        //etat.getChars().set(5,4,c);
        //std::cout << "crée le moteur à partir de l'état" << std::endl;
        Engine*eng = new Engine(etat);
        eng->addCommand(new LoadCommand("res/mapEngine.csv", "res/mapEngine_Grid.csv"));
        eng->update();
        etat.getGrid().set(18,2,bat);
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
                        eng->addCommand(new CreateCombatCommand(MilTypeId::MOUSQUETAIRE,18,2));
                        //eng->addCommand(new MoveCommand(18,2,5,1));
                        eng->update();
                    }
                    else if(hh==3){
                        std::cout << " *** Epoque"<<hh<<"***"<< std::endl;
                        
                        std::cout << "ajoute de nouvelle commande d'attaque" << std::endl;
                        eng->addCommand(new AttaqueCommand(10,10,2,9));
                        eng->update();
                        std::cout <<"Vérifie les points de vie de l'unité attaqué ont diminué:";
                        if (m2->getPv()<100){ std::cout << "OK" << std::endl; }
                        else{ std::cout << "Problème sur la commande" << std::endl; }
                    }
                    else if(hh==4){
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
    
void testJson(){
    /*Json::Value test;
    Json::Value test2;
    Json::Value test3;
    AttaqueCommand*att = new AttaqueCommand(8,5,6,3);
    att->serialized(test);
    Json::StyledWriter writer;
    test2.append(test);
    test3.append(test2);
    std::string output = writer.write(test3);
    //std::cout<<output<<std::endl;
    std::fstream fichier("./replay.txt",ios::in|ios::app);
    if(fichier){
        fichier << output << endl;
        fichier.close();
    }
    Json::Value root;
    std::ifstream file("./replay.txt");
    file >> root;
    Json::StyledWriter w;
    cout<<root[0].size()<<endl;
    AttaqueCommand*a =att->deserialized(root[0][0]);
    std::cout<<a->x<<std::endl;*/
    Json::Value full;
    sf::RenderWindow window(sf::VideoMode(1920, 1056),"Test Engine");
        std::cout<<"Touches"<<std::endl;
        std::cout<<"Mmaintenir <espace>:faire défiler  les époques"<<std::endl;
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
                        randoom.runReplay(*eng);
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
        std::string output;
        Json::StyledWriter writer;
        output=writer.write(eng->record);
        std::fstream fichier("./replay.txt",ios::in|ios::app);
        if(fichier){
            fichier << output << std::endl;
            fichier.close();
        }
        
            
}

void testReplay(){
    sf::RenderWindow window(sf::VideoMode(1920, 1056),"Replay");
    State state;
        state.addJoueur(new Joueur(1));
        state.addJoueur(new Joueur(2));
        state.getChars().resize(100,100);
        Military *m=new Military(MOUSQUETAIRE);
        Military *m1=new Military(EPEISTE);
        Colon *c = new Colon();
        Military *m2= new Military(MOUSQUETAIRE);
        Engine*eng = new Engine(state);
        m->setJ(1);
        m1->setJ(1);
        m->setCombat(60);
        m1->setCombat(60);
        m2->setCombat(60);
        m2->setJ(2);
        c->setJ(1);
        state.getChars().set(2,9,m2);
        state.getChars().set(5.3,8.1,m1);
        state.getChars().set(3,5,m);
        eng->addCommand(new LoadCommand("res/mapEngine.csv", "res/mapEngine_Grid.csv"));
        eng->update();
        Json::Value root;
        std::ifstream file("./replay.txt");
        file >> root;
        unsigned int i=0;
        unsigned int j;
        while (window.isOpen()){
            sf::Event event;
            
            while (window.pollEvent(event)){
                if (event.type == sf::Event::Closed)
                        window.close();
            }
                while (i < root.size()){
                    for (j=0;j<root[i].size();j++){
                    
                        Command* c;
                        c = c->deserialized(root[i][j]);
                        eng->addCommand(c);
                        eng->update();
                        render::TerrainLayer tMap(state.getTerrain());
                        tMap.initSurface();
                        render::GridLayer tGrid(state.getGrid());
                        tGrid.initSurface();    
                        render::CharsLayer tChars(state.getChars());
                        tChars.initSurface();
                        window.clear();
                        window.draw(*(tMap.getSurface()));
                        window.draw(*(tGrid.getSurface()));
                        window.draw(*(tChars.getSurface()));
                        window.display();
                        
                    
                    }
                    i++;
                }
            //  
        }
        
}
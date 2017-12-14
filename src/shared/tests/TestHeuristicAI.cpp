/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "TestHeuristicAI.h"
#include "state.h"
#include "engine.h"
#include "render.h"
#include "ai.h"

using namespace ai;
using namespace render;
using namespace engine;
using namespace state;

void testHeuristicAI(){
    sf::RenderWindow window(sf::VideoMode(1920, 1056),"Heuristic_ai");
    
    State etat;
    etat.getChars().resize(20,11);
    etat.addJoueur(new Joueur(0));
    etat.addJoueur(new Joueur(1));

    Military *m3=new Military(MOUSQUETAIRE);
    Military *m4=new Military(EPEISTE);
    Military *m5= new Military(MOUSQUETAIRE);
    m3->setJ(2);
    m4->setJ(2);
    m5->setJ(2);
    
    etat.getChars().set(5,5,m3);
    etat.getChars().set(2,8,m4);
    etat.getChars().set(15,9,m5);
    etat.getChars().set(19,7,new Military(MOUSQUETAIRE));
    etat.getChars().set(15,1,new Military(EPEISTE));
    etat.getChars().set(10,3,new Military(MOUSQUETAIRE));
    
    Engine eng(etat);
        
    eng.addCommand(new engine::LoadCommand("res/mapEngine.csv", "res/mapEngine_Grid.csv"));
    eng.update();
    
    //HeuristicAI heuristic(etat);
    //heuristic.run(eng);
    
    render::TerrainLayer tMap(eng.getState().getTerrain());
    tMap.initSurface();
    render::GridLayer tGrid(eng.getState().getGrid());
    tGrid.initSurface();    
    render::CharsLayer tChars(eng.getState().getChars());
    tChars.initSurface();
        
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
            /*if (event.type == eventstate){
                window.close();
            }*/
        }
        render::TerrainLayer tMap(eng.getState().getTerrain());
        tMap.initSurface();
        render::GridLayer tGrid(eng.getState().getGrid());
        tGrid.initSurface();    
        render::CharsLayer tChars(eng.getState().getChars());
        tChars.initSurface();
        window.clear();
        window.draw(*(tMap.getSurface()));
        window.draw(*(tGrid.getSurface()));
        window.draw(*(tChars.getSurface()));
        window.display();
    }
}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "TestRender.h"

using namespace render;




void testRender() {
    // on crée la fenêtre (12*8)
    sf::RenderWindow window(sf::VideoMode(1152, 768), "Test sur le rendu"); 
    
    // on crée un état
    state::State etat;
    etat.getChars().resize(3,6);
    etat.getGrid().resize(3, 6);
    etat.getTerrain().resize(3, 6);
    
    // test sur la liste des personnages
    state::Military* ep = new state::Military(state::EPEISTE);
    ep->setOrientation(state::EAST);
    
    state::Military* msq = new state::Military(state::MOUSQUETAIRE);
    msq->setOrientation(state::SOUTH);
    
    state::Military* mt = new state::Military(state::MITRAILLEUR);
    mt->setOrientation(state::NORTH_EAST);
    
    etat.getChars().set(2, 5, msq);
    etat.getChars().set(0, 2, ep);
    etat.getChars().set(1, 4, new state::Colon());
    etat.getChars().set(0, 1, new state::Military(state::CATAPULT));
    etat.getChars().set(2, 3, mt);
    
    render::ElementTabLayer tChars(etat.getChars(), 3);
    tChars.initSurface();
    
    // test sur la grille
    etat.getGrid().set(0, 0, new state::Batiment(state::WATER_MILL)), 
    etat.getGrid().set(1, 1, new state::Paysage(state::COLLINE1));
    etat.getGrid().set(1, 3, new state::Batiment(state::SHRINE));
    etat.getGrid().set(1, 5, new state::Paysage(state::PLANTE1));
    etat.getGrid().set(2, 2, new state::Batiment(state::PYRAMID));
    
    render::ElementTabLayer tGrid(etat.getGrid(), 2);
    tGrid.initSurface();
    
    // test sur le terrain
    etat.getTerrain().set(0, 0, new state::Terrain(state::PLAINE));
    etat.getTerrain().set(0, 1, new state::Terrain(state::PLAINE));
    etat.getTerrain().set(0, 2, new state::Terrain(state::PLAINE));
    etat.getTerrain().set(0, 3, new state::Terrain(state::PLAINE));
    etat.getTerrain().set(0, 4, new state::Terrain(state::PLAINE));
    etat.getTerrain().set(0, 5, new state::Terrain(state::PLAINE));
    
    etat.getTerrain().set(1, 0, new state::Terrain(state::PLAINE));
    etat.getTerrain().set(1, 1, new state::Terrain(state::DESERT));
    etat.getTerrain().set(1, 2, new state::Terrain(state::PLAINE));
    etat.getTerrain().set(1, 3, new state::Terrain(state::PLAINE));
    etat.getTerrain().set(1, 4, new state::Terrain(state::PLAINE));
    etat.getTerrain().set(1, 5, new state::Terrain(state::PLAINE));
    
    etat.getTerrain().set(2, 0, new state::Terrain(state::DESERT));
    etat.getTerrain().set(2, 1, new state::Terrain(state::PLAINE));
    etat.getTerrain().set(2, 2, new state::Terrain(state::PLAINE));
    etat.getTerrain().set(2, 3, new state::Terrain(state::MOUNTAIN));
    etat.getTerrain().set(2, 4, new state::Terrain(state::PLAINE));
    etat.getTerrain().set(2, 5, new state::Terrain(state::PLAINE));
    
    render::ElementTabLayer tMap(etat.getTerrain(), 1);
    tMap.initSurface();      

    // on fait tourner la boucle principale
    while (window.isOpen())
    {
        // on gère les évènements
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }
        // on dessine le niveau
        window.clear();
        window.draw(*(tMap.getSurface()));
        window.draw(*(tGrid.getSurface()));
        window.draw(*(tChars.getSurface()));
        window.display();
    }
} // testRender();  
    
    
    
    
    
    
    
void testMap(){
    
    // on crée la fenêtre (12*8)
    sf::RenderWindow window(sf::VideoMode(1152, 768), "Test sur le rendu"); 
    
    // on crée un état
    state::State etat; 
    
    
    
    
    etat.getChars().resize(12,8);

    state::Military* ep = new state::Military(state::MilTypeId::EPEISTE);
    ep->setOrientation(state::Direction::SOUTH_WEST);
    
    state::Military* msq = new state::Military(state::MilTypeId::MOUSQUETAIRE);
    msq->setOrientation(state::Direction::SOUTH);
    
    state::Military* mt = new state::Military(state::MilTypeId::MITRAILLEUR);
    mt->setOrientation(state::Direction::NORTH_EAST);
    
    etat.getChars().set(3, 1, msq);
    etat.getChars().set(1, 1, ep);
    etat.getChars().set(4, 3, new state::Colon());
    etat.getChars().set(2, 7, new state::Military(state::MilTypeId::CATAPULT));
    etat.getChars().set(6, 0, mt);
    
    render::ElementTabLayer tChars(etat.getChars(), 3);
    tChars.initSurface();   
    
    
    etat.getTerrain().load("res/mapTestRendu_Terrain.csv", 1);
    etat.getGrid().load("res/mapTestRendu_Grid.csv", 2);   
    
    render::ElementTabLayer tMap(etat.getTerrain(), 1);
    tMap.initSurface();
    
    render::ElementTabLayer tGrid(etat.getGrid(), 2);
    tGrid.initSurface();
    
    
    
    
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(*(tMap.getSurface()));
        window.draw(*(tGrid.getSurface()));
        window.draw(*(tChars.getSurface()));
        window.display();
    }
}   // fin testMap

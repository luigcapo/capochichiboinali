/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "TestEngine.h"
#include "state.h"
#include <SFML/Graphics.hpp>

using namespace state;

namespace engine{
    
    void testEngine(){
        
        /*
         * 
         * Epoque 1
         * 
         * */
        sf::RenderWindow window(sf::VideoMode(200,200),"Test Engine");
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
        Batiment *b=new Batiment(WATER_MILL);
        Batiment *bb=new Batiment(WATER_MILL);
        m->setJ(1);
        m1->setJ(1);
        m1->setCombat(30);
        m2->setJ(2);
        c->setJ(1);
        etat.getChars().set(6,6,bb);
        etat.getChars().set(7,7,b);
        etat.getChars().set(3,5,m);
        etat.getChars().set(4,4,m1);
        etat.getChars().set(5,4,c);
        etat.getChars().set(5,5,m2);
        //std::cout << "crée le moteur à partir de l'état" << std::endl;
        Engine*eng = new Engine(etat);
        
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
                    }
                
                    else if(hh==2){
                    std::cout << " *** Epoque"<<hh<<"***"<< std::endl;
                    std::cout<<"Vérifie le déplacement";
                    if (etat.getChars().get(7,7)->getTypeId()==2){ std::cout << "OK" << std::endl; }
                    else{ std::cout << "Problème sur la commande" << std::endl; }
                    std::cout << "ajoute de nouvelle commande d'attaque" << std::endl;
                    eng->addCommand(new AttaqueCommand(4,4,5,5));
                    eng->addCommand(new MoveCommand(5,4,6,6));
                   
                    eng->update();
                    std::cout <<"Vérifie les points de vie de l'unité attaqué ont diminué:";
                    if (m2->getPv()<100){ std::cout << "OK" << std::endl; }
                    else{ std::cout << "Problème sur la commande" << std::endl; }
                    std::cout<<etat.getChars().get(5,5)->getTypeId()<<std::endl;
                    }
                    hh++;
                    
            }
        }
            if (event.type == sf::Event::Closed)
                        window.close();
        }
        
        }
           
      
        
        
    }
}// fin testEngine
    


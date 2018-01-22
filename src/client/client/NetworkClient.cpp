/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "NetworkClient.h"
#include "state.h"
#include <iostream>
#include <SFML/Network/Http.hpp>
#include <SFML/Graphics.hpp>
#include <memory>
#include <thread>
#include "unistd.h"
#include "engine/LoadCommand.h"

using namespace std;
using namespace render;
using namespace ai;
using namespace state;
using namespace engine;

namespace client{

    NetworkClient::NetworkClient(const std::string& url, int port, int character):url(url),port(port),character(character) {}

    std::string NetworkClient::getGameStatus() {
        // envoyer requete GameService
        sf::Http connection("http://localhost", port);
        sf::Http::Request* request=new sf::Http::Request;;
        sf::Http::Response response;
        Json::Value data;
        
        request->setUri("/Game");
        request->setMethod(sf::Http::Request::Get);
        response= connection.sendRequest(*request);
        if(response.getStatus() != sf::Http::Response::Ok)
            return "Problème serveur";
        else
            data["GameStatus"]=response.getBody();
        cout << data << endl;
        return data["GameStatus"].asString();
    }

    void NetworkClient::run() {
        sf::Http http(url,port);
        int status;
        while (getGameStatus() == "CREATING"){
            Json::Value data;
            sf::Http::Request request;
            request.setMethod(sf::Http::Request::Post);
            request.setUri("/player/"+character);
            sf::Http::Response response = http.sendRequest(request);
            status = response.getStatus();
            if(status == sf::Http::Response::Ok)
                std::cout<< "joueur ajouté à la partie"<<std::endl;
            else{
                std::cout<<"erreur" + response.getStatus()<<std::endl;
            }
        }
        
        /* On crée la fenetre */
        sf::RenderWindow window(sf::VideoMode(1152, 768),"Client");
        
        EngineClient* engine = new EngineClient(url,port);
        engine->addCommand(new LoadCommand("res/mapTestRendu_Terrain.csv","res/mapTestRendu_Grid.csv"));
        engine->update();
        
        /* Configuration du rendu */
        TerrainLayer tMap(engine->getState().getTerrain());
        tMap.initSurface();
        GridLayer tGrid(engine->getState().getGrid());
        tGrid.initSurface();
        CharsLayer tChars(engine->getState().getChars());
        tChars.initSurface();
        
        
        AI *random;
        random = new RandomAI();
        /* On crée et on lance le thread secondaire pour le moteur de jeu */
        thread th(&EngineClient::runThread, engine, random);
        /*while(1){
            if(getGameStatus() == "RUNNING"){
                Json::Value out;
                if(getServerCommands(out))
                    player_ai.get()->run(engine);
            }
        }*/
        
        
        
        std::cout << "Touches :" << std::endl;
        std::cout << "    <espace> : passer à l'époque suivante" << std::endl;
        
        while (window.isOpen()){
            sf::Event event;
            while (window.pollEvent(event)){
                if (event.type == sf::Event::Closed){
                    window.close();
                }
                else if (event.key.code == sf::Keyboard::Space){
                    if(getGameStatus() == "RUNNING"){
                        //player_ai.get()->run(engine);
                        engine->setRun_randomAI(true);
                    }
                    else
                        window.close();
                }
            }
            tMap.initSurface();
            tGrid.initSurface();
            tChars.initSurface();
            window.clear();
            window.draw(*(tMap.getSurface()));
            window.draw(*(tGrid.getSurface()));
            window.draw(*(tChars.getSurface()));
            window.display();
        } /* while window open */
        th.join();
    }

}
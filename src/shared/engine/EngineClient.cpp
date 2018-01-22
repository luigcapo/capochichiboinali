/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "EngineClient.h"
#include <fstream>
#include <iostream>
#include <thread>
#include "unistd.h"
#include "state/Mobile.h"
#include <SFML/Network/Http.hpp>
#include "state.h"
#include "LoadCommand.h"

using namespace state;
using namespace ai;

namespace engine {

    EngineClient::EngineClient(std::string url, int port):url(url),port(port) {
        currentState.getChars().resize(12,8);
        
        /* On ajoute 2 joueurs */
        currentState.addJoueur(new Joueur(1));
        currentState.addJoueur(new Joueur(2));
        
        Military *m=new Military(MOUSQUETAIRE);
        Military *m1= new Military(MOUSQUETAIRE);
        Military *m2=new Military(EPEISTE);
        Military *m3=new Military(EPEISTE);
        Colon *c1 = new Colon();
        Colon *c2 = new Colon();
        m->setJ(1);
        m1->setJ(2);
        m2->setJ(1);
        m3->setJ(2);
        m->setCombat(40);
        m1->setCombat(40);
        m2->setCombat(60);
        m3->setCombat(60);
        c1->setJ(1);
        c2->setJ(2);
        m1->setOrientation(WEST);
        m2->setOrientation(SOUTH);
        m3->setOrientation(NORTH);
        c1->setOrientation(state::Direction::SOUTH_EAST);
        currentState.getChars().set(9,2,m);
        currentState.getChars().set(3,7,m1);
        currentState.getChars().set(5,5,c2);
        currentState.getChars().set(10,3,m2);
        currentState.getChars().set(4,4,m3);
        currentState.getChars().set(6,1,c1);
    }

    void EngineClient::addCommand(Command* cmd) {
        /* push_back commande ???!!!  */
        //currentCommands.push_back(cmd);
        Json::Value data;
        cmd->serialized(data);
        
        // envoie de la commande au serveur
        sf::Http connection(url, port);
        sf::Http::Request* request=new sf::Http::Request;;
        sf::Http::Response response;
        
        request->setUri("/Command");
        request->setMethod(sf::Http::Request::Put);
        request->setBody(data.toStyledString());
        response= connection.sendRequest(*request);
        if(response.getStatus() != sf::Http::Response::Ok)
            std::cout << "Commande non envoyée" << std::endl; 
        /*else*/
    }

    void EngineClient::executeCom(Command* c) {

    }

    state::State& EngineClient::getState() {
        return currentState;
    }

    void EngineClient::resize(int c) {
        currentCommands.resize(c);
    }

    void EngineClient::runThread(ai::AI* random) {
        std::lock_guard<std::mutex> l(engine_mutex);
        while(1){
            if(run_randomAI == true){
                random->runClient(*this);
                run_randomAI=false;
            }
        }
    }

    void EngineClient::setRun_randomAI(bool run_randomAI) {
        std::lock_guard<std::mutex> l(std::mutex);
        this->run_randomAI = run_randomAI;
    }

    bool EngineClient::getRun_randomAI() const {
        std::lock_guard<std::mutex> l(std::mutex);
        return this->run_randomAI;
    }

    void EngineClient::undo(std::stack<Action*>& actions) {
        while(!actions.empty()){
            
            actions.top()->undo(currentState);
            actions.pop();
        }
    }

    std::stack<Action*> EngineClient::update() {
        std::stack<Action*> actions;
        
        /* On récupère une commande à partir du serveur */
        Json::Value in;
        sf::Http connection(url, port);
        sf::Http::Request request;
        request.setMethod(sf::Http::Request::Get);
        request.setUri("/Command");
        sf::Http::Response response;
        response= connection.sendRequest(request);
        if(response.getStatus() != sf::Http::Response::Ok){
            std::cout << "Aucune commande disponible" << std::endl;
        }
        in = response.getBody();
        Json::Reader jsonReader;
        jsonReader.parse(0,in);
        Command *c;
        c = c->deserialized(in);
        currentCommands.push_back(c);
        /*switch (in["Command"].asInt()){
            case 1:
            {
                std::string file_name_map = in["name_map"].asString();
                std::string file_name_grid = in["name_grid"].asString();
                currentCommands.push_back(new engine::LoadCommand::LoadCommand("name_map","name_grid"));
            }
                break;
            case 2:
            {
                int x = in["x"].asInt();
                int y = in["y"].asInt();
                int x1 = in["x1"].asInt();
                int y1 = in["y1"].asInt();
                currentCommands.push_back(new engine::MoveCommand(x,y,x1,y1));
            }
                break;
            case 3:
            {
                int x = in["x"].asInt();
                int y = in["y"].asInt();
                int x1 = in["x1"].asInt();
                int y1 = in["y1"].asInt();
                currentCommands.push_back(new engine::AttaqueCommand(x,y,x1,y1));
            }
                break;
            default:
                break;      
        }*/
        
        for(auto command : currentCommands){
            command->execute(currentState,actions);
        }
        currentCommands.clear();
        return actions;
    }

    std::stack<Action*> EngineClient::updateReplay() {
        std::stack<Action*> actions;
        Json::Value record1;
        
        for(auto command : currentCommands){
            Json::Value record2;
            command->serialized(record2);
            command->execute(currentState,actions);
            record1.append(record2);
            
        }
        
        currentCommands.clear();
        record.append(record1);
        return actions;
    }
    
    int EngineClient::getPort() const {
        return port;
    }

    void EngineClient::setPort(int port) {
        this->port = port;
    }

    const std::string& EngineClient::getUrl() const {
        return url;
    }

    void EngineClient::setUrl(const std::string& url) {
        this->url = url;
    }

}
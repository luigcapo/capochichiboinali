/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "NetworkClient.h"
#include <SFML/Network/Http.hpp>


namespace client{

    NetworkClient::NetworkClient(EngineClient& engine, const std::string& url, int port, int character):engine(engine), url(url),port(port),character(character) {
        
    }

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
        return data["GameStatus"].asString();
    }

    bool NetworkClient::getServerCommands(Json::Value& out) {
        // envoyer requete CommandsService
        return false;
    }

    void NetworkClient::putServerCommand(engine::Command* command) {
        // envoyer commande au serveur
    }

    void NetworkClient::run() {
        
    }

}
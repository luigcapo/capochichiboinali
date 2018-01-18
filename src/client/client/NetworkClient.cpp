/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "NetworkClient.h"

namespace client{

    NetworkClient::NetworkClient(EngineClient& engine, const std::string& url, int port, int character):engine(engine), url(url),port(port),character(character) {
        
    }

    std::string NetworkClient::getGameStatus() {
        // envoyer requete GameService
    }

    bool NetworkClient::getServerCommands(Json::Value& out) {
        // envoyer requete CommandsService
    }

    void NetworkClient::putServerCommand(engine::Command* command) {
        // envoyer commande au serveur
    }

    void NetworkClient::run() {
        
    }

}
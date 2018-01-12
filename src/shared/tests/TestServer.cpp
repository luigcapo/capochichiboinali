/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "TestServer.h"

using namespace std;
using namespace server;

void testServer(int port,std::string name){
    sf::Http connection("http://localhost", port);
    sf::Http::Request* request = new sf::Http::Request;
    sf::Http::Response response;

    request->setUri("/game");
    request->setMethod(sf::Http::Request::Get);
    response = connection.sendRequest(*request);
    
    if(response.getStatus() == sf::Http::Response::ConnectionFailed) {
        std::cout << "Impossible de se connecter au serveur" << std::endl;
        std::cout << "Vérifiez que le serveur a bien été mis en marche" << std::endl;
        delete request;
        return;
    }
    else if(response.getStatus() == sf::Http::Response::NotFound) {
        std::cout << "Erreur la partie demandée n'existe pas !" << std::endl;
        std::cout << "Arrêt de la connection !" << std::endl;

        delete request;
        return;
    }
    
}
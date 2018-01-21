/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "TestServer.h"

using namespace std;
using namespace server;

void testServer(int port){
    int i =1;
    std::string str;
    std::string name;

    sf::Http connection("http://localhost", port);
    sf::Http::Request* request = new sf::Http::Request;
    sf::Http::Response response;
    sf::Http::Response response_get;
    cout << "Voulez vous rajoutez un joueur ? (Oui/Non)" << endl;
    cin >> str;
    if (str == "Oui"||str=="OUI"||str=="oui"){
        cout << "Entrer un nom de joueur" << endl;
        cin >> name;
        Json::Value out;
        out["name"]=name;
        request->setUri("/player");
        request->setMethod(sf::Http::Request::Put);
        request->setField("Content-Type", "application/x-www-form-urlencoded");
        request->setBody(out.toStyledString());
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
        else if(response.getStatus() == 503) {
            std::cout << "Plus de place disponible pour cette partie"<< std::endl;
            delete request;
            return;
        }
        else if(response.getStatus()==sf::Http::Response::InvalidResponse){
            std::cout << "reponse invalide" << std::endl;
            delete request;
            return;
        }
        else if(response.getStatus()==sf::Http::Response::BadRequest){
            std::cout << "Bad Request" << std::endl;
            delete request;
            return;
        }
        else if(response.getStatus()==sf::Http::Response::Created){
            std::cout<<"Nouveau joueur ajouté"<<std::endl;
        }
    }
    request = new sf::Http::Request;
    while(1){
        request->setUri("/player/"+std::to_string(i));
        request->setMethod(sf::Http::Request::Get);
        request->setField("Content-Type", "application/x-www-form-urlencoded");
        response_get = connection.sendRequest(*request);
        if(response_get.getStatus()==sf::Http::Response::Ok){
            std::cout<<response_get.getBody()<<std::endl;
            i++;
        }
        else {
             break;
        }
    }
    
}
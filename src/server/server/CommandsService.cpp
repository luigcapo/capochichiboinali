/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "CommandsService.h"

#include "ServiceException.h"

#include <locale>
#include <memory>
#include <string>

using namespace std;
using namespace engine;

namespace server {

    CommandsService::CommandsService():AbstractService("/Command") {}

    HttpStatus CommandsService::get(Json::Value& out, int id) const {
        const Commande c = commandes.back();
        int name = c.name;
        switch(name){
            case 1:
            {
                out["Command"] = c.name;
                out["name_map"] = c.terrain;
                out["name_grid"] = c.grid;
            }
                break;
            case 2:
            {
                out["Command"] = c.name;
                out["x"] = c.x;
                out["y"] = c.y;
                out["x1"] = c.x1;
                out["y1"] = c.y1;
            }    
                break;
            case 3:
            {
                out["Command"] = c.name;
                out["x"] = c.x;
                out["y"] = c.y;
                out["x1"] = c.x1;
                out["y1"] = c.y1;
            }    
                break;
            default:
                return HttpStatus::NOT_FOUND;
                break;
        }
        return HttpStatus::OK;
        /*const engine::Command* c = commands.pop_back();
        if(!c)
            throw ServiceException(HttpStatus::NO_CONTENT,"Liste de commandes vide");
        c->serialized(out);
        return HttpStatus::OK;*/
    }

    HttpStatus CommandsService::put(Json::Value& out, const Json::Value& in) {
        int name = in["Command"].asInt();
        switch(name){
            case 1:
            {
                std::string terrain = in["name_map"].asString();
                std::string grid = in["name_grid"].asString();
                commandes.push_back(Commande(name,-1,-1,-1,-1,terrain,grid));
            }
                break;
            case 2:
            {
                std::string s1 = "abcd";
                int x = in["x"].asInt();
                int y = in["y"].asInt();
                int x1 = in["x1"].asInt();
                int y1 = in["y1"].asInt();
                commandes.push_back(Commande(name,x,y,x1,y1,s1,s1));
            }    
                break;
            case 3:
            {
                std::string s1 = "abcd";
                int x = in["x"].asInt();
                int y = in["y"].asInt();
                int x1 = in["x1"].asInt();
                int y1 = in["y1"].asInt();
                commandes.push_back(Commande(name,x,y,x1,y1,s1,s1));
            }    
                break;
            default:
                return HttpStatus::BAD_REQUEST;
                break;
        }
        return HttpStatus::OK;
        
        
        /*switch (in["Command"].asInt()){
            case 1:
            {
                std::string file_name_map = in["name_map"].asString();
                std::string file_name_grid = in["name_grid"].asString();
                commands.push_back(new engine::LoadCommand("name_map","name_grid"));
            }
                break;
            case 2:
            {
                int x = in["x"].asInt();
                int y = in["y"].asInt();
                int x1 = in["x1"].asInt();
                int y1 = in["y1"].asInt();
                commands.push_back(new engine::MoveCommand(x,y,x1,y1));
            }
                break;
            case 3:
            {
                int x = in["x"].asInt();
                int y = in["y"].asInt();
                int x1 = in["x1"].asInt();
                int y1 = in["y1"].asInt();
                commands.push_back(new engine::AttaqueCommand(x,y,x1,y1));
            }
                break;
            default:
                return HttpStatus::BAD_REQUEST;
                break;      
        }
        return HttpStatus::OK;*/
    }

}
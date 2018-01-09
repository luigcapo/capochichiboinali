/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <locale>

#include "PlayerService.h"

namespace server {

    PlayerService::PlayerService(Game& game):game(game) {}

    HttpStatus PlayerService::get(Json::Value& out, int id) const {
        const Player*player = game.player(id);
        if (!player)
            throw ServiceException(HttpStatus::NOT_FOUND,"Invalid user id");
        else if(id<0)
            throw ServiceException(HttpStatus::NOT_FOUND,"Invalid user id");
        out["name"]=player->name;
        out["free"]=player->free;
        return HttpStatus::OK;
    }

    HttpStatus PlayerService::post(const Json::Value& in, int id) {
        const Player*player = game.player(id);
        if(!player)
            throw ServiceException(HttpStatus::NOT_FOUND,"Invalid user id");
        Player*playermod;
        if(in.isMember("name"))
            playermod->name=in["name"].asString();
        if(in.isMember("free"))
            playermod->free=in["free"].asBool();
        std::vector<Player> p=game.getPlayers();
        p[id]= playermod;
        game.setPlayers(p);
        return HttpStatus::NO_CONTENT;
    }

    HttpStatus PlayerService::put(Json::Value& out, const Json::Value& in) {
        Player* playerone;
        std::string name=in["name"].asString();
        bool free = in["free"].asBool();
        playerone->free=free;
        playerone->name=name;
        //if plus de place out f ressource
        int id = game.getPlayers().size();
        if (id>2)
            throw ServiceException(HttpStatus::OUT_OF_RESOURCES,"No more place");
        game.getPlayers().insert(id,playerone);
        out["id"]=id;
        return HttpStatus::CREATED;
    }

    HttpStatus PlayerService::remove(int id) {
        if(!(game.player(id)))
            throw ServiceException(HttpStatus::NOT_FOUND,"Invalid user id");
        game.getPlayers().erase(id);
        return HttpStatus::NO_CONTENT;
    }

}
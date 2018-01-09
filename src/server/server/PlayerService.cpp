/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <locale>

#include "PlayerService.h"
#include "ServiceException.h"

namespace server {

    PlayerService::PlayerService(Game& game):AbstractService("/player"),game(game) {}

    HttpStatus PlayerService::get(Json::Value& out, int id) const {
        const Player player = game.player(id);
        if (!(&(game.player(id))))
            throw ServiceException(HttpStatus::NOT_FOUND,"Invalid user id");
        else if(id<0)
            throw ServiceException(HttpStatus::NOT_FOUND,"Invalid user id");
        out["name"]=player.name;
        out["free"]=player.free;
        return HttpStatus::OK;
    }

    HttpStatus PlayerService::post(const Json::Value& in, int id) {
        const Player player = game.player(id);
        if(!&(game.player(id)))
            throw ServiceException(HttpStatus::NOT_FOUND,"Invalid user id");
        Player playermod;
        if(in.isMember("name"))
            playermod.name=in["name"].asString();
        if(in.isMember("free"))
            playermod.free=in["free"].asBool();
        std::vector<Player> p=game.getPlayer();
        p[id]= playermod;
        game.setPlayers(p);
        return HttpStatus::NO_CONTENT;
    }

    HttpStatus PlayerService::put(Json::Value& out, const Json::Value& in) {
        Player playerone;
        std::string name=in["name"].asString();
        bool free = in["free"].asBool();
        playerone.free=free;
        playerone.name=name;
        //if plus de place out f ressource
        auto id = game.getPlayer().end();
        int ide =game.getPlayer().size();
        if (ide>2)
            throw ServiceException(HttpStatus::OUT_OF_RESOURCES,"No more place");
        game.getPlayer().insert(id,playerone);
        out["id"]=ide;
        return HttpStatus::CREATED;
    }

    HttpStatus PlayerService::remove(int id) {
        if(!&(game.player(id)))
            throw ServiceException(HttpStatus::NOT_FOUND,"Invalid user id");
        game.getPlayer().erase(game.getPlayer().begin()+id);
        return HttpStatus::NO_CONTENT;
    }

}

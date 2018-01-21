/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <locale>

#include "PlayerService.h"
#include "ServiceException.h"

template<class T,typename ... Args>
std::unique_ptr<T> make_unique(Args ... args) {
    return std::unique_ptr<T>(new T(args ...));
}

namespace server {

    PlayerService::PlayerService(Game& game) : AbstractService("/player"),game(game) {}
    
    HttpStatus PlayerService::get(Json::Value& out, int id) const {
        const Player* player = game.getPlayer(id);
        if (!player)
            throw ServiceException(HttpStatus::NOT_FOUND,"Invalid player id");
        out["name"] = player->name;
        out["free"] = player->free;
        return HttpStatus::OK;
    }

    HttpStatus PlayerService::post(const Json::Value& in, int id) {
        const Player* player = game.getPlayer(id);
        if (!player)
            throw ServiceException(HttpStatus::NOT_FOUND,"Invalid player id");
        std::unique_ptr<Player> playermod (new Player(*player));
        if (in.isMember("name")) {
            playermod->name = in["name"].asString();
        }
        if (in.isMember("free")) {
            playermod->free = in["free"].asInt();
        }
        game.setPlayer(id,std::move(playermod));
        return HttpStatus::NO_CONTENT;
    }

    HttpStatus PlayerService::put(Json::Value& out, const Json::Value& in) {
        if(game.getPlayers().size()>1)
            throw ServiceException(HttpStatus::OUT_OF_RESOURCES,"Plus de places disponibles");
        std::string name = in["name"].asString();
        bool free = in["free"].asInt();
        out["id"] = game.addPlayer(make_unique<Player>(name,free));
        return HttpStatus::CREATED;
    }

    HttpStatus PlayerService::remove(int id) {
        const Player* player = game.getPlayer(id);
        if (!player)
            throw ServiceException(HttpStatus::NOT_FOUND,"Invalid player id");
        game.removePlayer(id);
        return HttpStatus::NO_CONTENT;
    }

}

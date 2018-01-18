/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "GameService.h"

namespace server {

    GameService::GameService(Game& game):AbstractService("/Game"), game(game) {
        
    }

    HttpStatus GameService::get(Json::Value& out, int id) const {
        
    }

}
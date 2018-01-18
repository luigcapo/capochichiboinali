/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "CommandsService.h"

namespace server {

    CommandsService::CommandsService():AbstractService("/Command") {
        
    }

    HttpStatus CommandsService::get(Json::Value& out, int id) const {
        
    }

    HttpStatus CommandsService::put(Json::Value& out, const Json::Value& in) {
        //commands.push_back();
    }

}
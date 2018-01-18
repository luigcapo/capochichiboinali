/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "VersionService.h"
#include "ServiceException.h"

namespace server {

    VersionService::VersionService():AbstractService("/Version") {
        
    }

    HttpStatus VersionService::get(Json::Value& out, int id) const {
        out["name"]= "projet IS";
        out["free"]= true;
        return HttpStatus::OK;
    }

}
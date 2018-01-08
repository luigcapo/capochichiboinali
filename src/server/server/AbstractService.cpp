/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "AbstractService.h"

namespace server {

    AbstractService::AbstractService(const std::string& pattern) {
        
    }

    AbstractService::~AbstractService() {
        
    }

    HttpStatus AbstractService::get(Json::Value& out, int id) const {
        
    }

    HttpStatus AbstractService::post(const Json::Value& in, int id) {
        
    }

    HttpStatus AbstractService::put(Json::Value& out, const Json::Value& in) {
        
    }

    HttpStatus AbstractService::remove(int id) {
        
    }

    const std::string& AbstractService::getPattern() const {
        
    }

    void AbstractService::setPattern(const std::string& pattern) {
        
    }

}
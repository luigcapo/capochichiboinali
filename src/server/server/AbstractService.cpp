/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "AbstractService.h"
#include "ServiceException.h"

namespace server {

    AbstractService::AbstractService(const std::string& pattern) {
        setPattern(pattern);
    }

    AbstractService::~AbstractService() {
        
    }

    HttpStatus AbstractService::get(Json::Value& out, int id) const {
        throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
    }

    HttpStatus AbstractService::post(const Json::Value& in, int id) {
        throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
    }

    HttpStatus AbstractService::put(Json::Value& out, const Json::Value& in) {
        throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
    }

    HttpStatus AbstractService::remove(int id) {
        throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
    }

    const std::string& AbstractService::getPattern() const {
        return pattern;
    }

    void AbstractService::setPattern(const std::string& pattern) {
        this->pattern = pattern;
    }

}
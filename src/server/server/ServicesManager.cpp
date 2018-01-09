/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ServicesManager.h"

namespace server {

    AbstractService* ServicesManager::findService(const std::string& url) const {
        throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
    }

    const std::vector<std::unique_ptr<AbstractService> >& ServicesManager::getServices() const {
        throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
    }

    void ServicesManager::setServices(const std::vector<std::unique_ptr<AbstractService> >& services) {
        throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
    }

    HttpStatus ServicesManager::queryService(std::string& out, const std::string& in, const std::string& url, const std::string& method) {
        throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
    }

    void ServicesManager::registerService(std::unique_ptr<AbstractService> service) {
        throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
    }

}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ServicesManager.h"

namespace server {

    AbstractService* ServicesManager::findService(const std::string& url) const {
        
    }

    const std::vector<std::unique_ptr<AbstractService> >& ServicesManager::getServices() const {
        
    }

    void ServicesManager::setServices(const std::vector<std::unique_ptr<AbstractService> >& services) {
        
    }

    HttpStatus ServicesManager::queryService(std::string& out, const std::string& in, const std::string& url, const std::string& method) {
        
    }

    void ServicesManager::registerService(std::unique_ptr<AbstractService> service) {
        
    }

}
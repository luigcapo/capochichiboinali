/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "SeviceException.h"

namespace server {

    int SeviceException::ServiceException(HttpStatus status, std::string msg) {
        
    }

    HttpStatus SeviceException::getHttpStatus() const {
        
    }

    void SeviceException::setHttpStatus(HttpStatus httpStatus) {
        
    }

    const std::string& SeviceException::getMsg() const {
        
    }

    void SeviceException::setMsg(const std::string& msg) {
        
    }

    HttpStatus SeviceException::status() const {
        
    }

    const char* SeviceException::what() const {
        
    }

}
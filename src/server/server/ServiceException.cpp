/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ServiceException.h"

namespace server {

    ServiceException::ServiceException(HttpStatus status, std::string msg): httpStatus(status),msg(msg) {

    }

    HttpStatus ServiceException::getHttpStatus() const {
        return httpStatus;
    }

    void ServiceException::setHttpStatus(HttpStatus httpStatus) {
        this->httpStatus = httpStatus;
    }

    const std::string& ServiceException::getMsg() const {
        return msg;
    }

    void ServiceException::setMsg(const std::string& msg) {
        this->msg = msg;
    }

    HttpStatus ServiceException::status() const {
        return httpStatus;
    }

    const char* ServiceException::what() const {
        return msg.c_str();
    }

}
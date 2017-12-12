/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Observable.h"

namespace engine{

    Observable::~Observable() {
        
    }

    void Observable::registerObserver(Observer* o) const {
        observers.push_back(o);
    }

    void Observable::notifyUpdated() const {
        for(auto observer : observers){
            observer->engineUpdated();
        }
    }

    void Observable::notifyUpdating() const {
        for(auto observer : observers){
            observer->engineUpdating();
        }
    }

}
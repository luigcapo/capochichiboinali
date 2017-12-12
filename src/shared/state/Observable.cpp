/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Observable.h"
#include <algorithm>

namespace state{
    Observable::~Observable() {
        /*for(std::vector<Observer*>::iterator it=observers.begin(); it!=observers.end(); ++it) {
            //delete (*it);
            (*it)->unregisterObserver(this);
        }*/
    }

    void Observable::registerObserver(Observer* o) const {
        observers.push_back(o);
    }

    void Observable::unregisterObserver(Observer* o) const {
        std::vector<Observer*>::iterator it=std::find(observers.begin(),observers.end(),o);
        if(it != observers.end()){observers.erase(it);}
    }
    
    void Observable::notifyObservers(const Event& e) const {
        for(auto observer : observers){
            observer->stateChanged(e);
        }
    }

}
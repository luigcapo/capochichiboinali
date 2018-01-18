/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "EngineClient.h"

namespace client {

    void EngineClient::addCommand(engine::Command* cmd) {
        
    }

    void EngineClient::runThread(ai::AI* random) {
        
    }

    int EngineClient::getEpoch() const {
        return epoch;
    }

    void EngineClient::setEpoch(int epoch) {
        this->epoch = epoch;
    }

}
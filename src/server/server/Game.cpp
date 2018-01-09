/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdexcept>

#include "Game.h"

namespace server {

    Game::Game() {
        
    }

    Player& Game::player(int i) {
        return players[i];
    }

    const std::vector<Player>& Game::getPlayers() const {
        return players;
    }

    void Game::setPlayers(const std::vector<Player>& players) {
        int j;
        if(this->players.size()!=players.size())
            throw std::logic_error("Taille incomptatible");
        for (j=0;j<this->players.size();j++){
            this->players[j]=players[j];
        }
        
    }

}
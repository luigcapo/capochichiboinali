/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Commande.h"

namespace server {

    Commande::Commande(int name, int x, int y, int x1, int y1, std::string terrain, std::string grid):name(name),x(x),y(y),x1(x1),y1(y1),terrain(terrain),grid(grid) {
        
    }

}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Surface.h"
#include "Tile.h"

namespace render{

    void Surface::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        // on applique la transformation de l'entité -- on la combine avec celle qui a été passée par l'appelant
        states.transform *= getTransform(); // getTransform() est définie par sf::Transformable

        // on applique la texture
        states.texture = &texture;

        // on peut aussi surcharger states.shader ou states.blendMode si nécessaire

        // on dessine le tableau de vertex
        target.draw(quads, states);
    }

    void Surface::initQuads(int count) {
        for(int i=0;i<count;i++){ 
          sf::VertexArray quadd(sf::Quads, 4);
        }
        
    }


    void Surface::setSpriteLocation(int i, int x, int y) {
            quads[i].position = sf::Vector2f(x, y);
        
    }

    void Surface::setSpriteTexture(int i, const Tile& tex) {
        quads[i].texCoords=sf::Vector2f(tex.getX(),tex.getY());
    }

    void Surface::loadTexture(const std::string& image_file) {
        texture.loadFromFile(image_file);
    }


}
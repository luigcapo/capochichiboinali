/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Surface.h"
#include "Tile.h"

namespace render{

    void Surface::loadTexture(const std::string& image_file) {
        // on charge la texture du tileset
        texture.loadFromFile(image_file);
    }
    
    void Surface::initQuads(int count) {
        //on crée un nombre de quads/sprites égal au nombre de cellules dans la grille
        for(int i=0; i<count; i++){
            // création d'un quad
            sf::VertexArray quad(sf::Quads, 4);
        }
    }
    
    /*
    void Surface::setSpriteLocation(int i, int x, int y) {
        
        //fixe la position de la cellule(tile) i
        
        sf::Vertex* quad = &quads[i];
        
        quad[0].position = sf::Vector2f(x, y);
        quad[1].position = sf::Vector2f(x, y);
        quad[2].position = sf::Vector2f(x, y);
        quad[3].position = sf::Vector2f(x, y);
    }
    
    void Surface::setSpriteTexture(int i, const Tile& tex) {
        
        //fixe la texture de la cellule i
        
        sf::Vertex* quad = &quads[i];
        
        quads[i].texCoords=sf::Vector2f(tex.getX(),tex.getY());
    }
    
     * 
     * */
    
    void Surface::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        // on applique la transformation de l'entité
        states.transform *= getTransform();

        // on applique la texture du tileset
        states.texture = &texture;

        // on peut aussi surcharger states.shader ou states.blendMode si nécessaire

        // et enfin on dessine le tableau de vertex
        target.draw(quads, states);
    }
    
}
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
        quads.setPrimitiveType(sf::Quads);
        quads.resize(4*count); // count = nombre de sprites
    }
    
    // A REVOIR.... Taille tuile: 96*96
    void Surface::setSpriteLocation (int i, int x, int y, const Tile& tex) {
        // Surface::setSpriteLocation(int i, int x, int y, const Tile& tex)
        
        // fixe les coordonnées des quatre coins du carré où doit être dessiné la tuile à l’écran
        // i: numero du quad à définir
        // x: position tuile x
        // y: position tuile y
        
        sf::Vertex* quad = &quads[4*i];
        
        int tx = tex.getWidth();
        int ty = tex.getHeight();
        
        quad[0].position = sf::Vector2f( x*tx, y*ty );
        quad[1].position = sf::Vector2f( (x+1)*tx, y*ty );
        quad[2].position = sf::Vector2f( (x+1)*tx, (y+1)*ty );
        quad[3].position = sf::Vector2f( x*tx, (y+1)*ty );
        
    }
    
    void Surface::setSpriteLocationMap2 (int i, int x, int y, const Tile& tex) {
        
        sf::Vertex* quad = &quads[4*i];
        
        int tx = tex.getWidth();
        int ty = tex.getHeight();
        
        quad[0].position = sf::Vector2f( x*tx+tx/2, y*ty+ty/2 );
        quad[1].position = sf::Vector2f( (x+1)*tx+tx/2, y*ty+ty/2 );
        quad[2].position = sf::Vector2f( (x+1)*tx+tx/2, (y+1)*ty+ty/2 );
        quad[3].position = sf::Vector2f( x*tx+tx/2, (y+1)*ty+ty/2 );
        
    }
    
    void Surface::setSpriteTexture(int i, const Tile& tex) {
        
        // fixe les coordonnées des quatre coins de la tuile à sélectionner dans la texture
        
        sf::Vertex* quad = &quads[4*i];
        
        //int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
        //int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);
        
        quad[0].texCoords = sf::Vector2f( tex.getX(), tex.getY() );
        quad[1].texCoords = sf::Vector2f( tex.getX() + tex.getWidth(), tex.getY());
        quad[2].texCoords = sf::Vector2f( tex.getX() + tex.getWidth(), tex.getY() + tex.getHeight() );
        quad[3].texCoords = sf::Vector2f( tex.getX(), tex.getY() + tex.getHeight() );
    }
    
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
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Texture.h"

namespace state{

     int texturetext(){
    // on crée la fenêtre
    sf::RenderWindow window(sf::VideoMode(528, 256), "Tilemap");

    // on définit le niveau à l'aide de numéro de tuiles
    const int level[] =
    {
        2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
        19, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 21,
        19, 20, 20, 20, 20, 20, 20, 20, 26, 20, 20, 20, 20, 123, 20, 21,
        19, 20, 20, 39, 40, 41, 40, 40, 77, 130, 20, 20, 20, 20, 20, 21,
        19, 20, 20, 20, 75, 75, 75, 130, 130, 130, 149, 150, 20, 20, 20, 21,
        19, 20, 20, 20, 130, 147, 130, 130, 149, 150, 20, 20, 20, 20, 20, 21,
        19, 123, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 21,
        36, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 38,
    };

    // on crée la tilemap avec le niveau précédemment défini
    TileMap map;
    if (!map.load("res/test.png", sf::Vector2u(33, 33), level, 16, 8))
        return -1;

    // on fait tourner la boucle principale
    while (window.isOpen())
    {
        // on gère les évènements
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        // on dessine le niveau
        window.clear();
        window.draw(map);
        window.display();
    }
    return 0;
}
}
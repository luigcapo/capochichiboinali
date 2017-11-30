/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Point.h"

namespace ai{

    Point::Point(int x, int y, int w) {
        this->weight = w;
        this->x = x;
        this->y = y;
    }

    int Point::getWeight() const {
        return this->weight;
    }

    void Point::setWeight(int weight) {
        this->weight = weight;
    }

    int Point::getX() const {
        return this->x;
    }

    int Point::getY() const {
        return this->y;
    }

    void Point::setX(int x) {
        this->x = x;
    }

    void Point::setY(int y) {
        this->y = y;
    }

    Point Point::transform(state::Direction d) {
        
        if(d == state::Direction::EAST){
            return Point(x+1, y, weight);
        }
        else if(d == state::Direction::NORTH){
            return Point(x, y-1, weight);
        }
        else if(d == state::Direction::NORTH_EAST){
            return Point(x+1, y-1, weight);
        }
        else if(d == state::Direction::NORTH_WEST){
            return Point(x-1, y-1, weight);
        }
        else if(d == state::Direction::SOUTH){
            return Point(x, y+1, weight);
        }
        else if(d == state::Direction::SOUTH_EAST){
            return Point(x+1, y+1, weight);
        }
        else if(d == state::Direction::SOUTH_WEST){
            return Point(x-1, y+1, weight);
        }
        else if(d == state::Direction::WEST){
            return Point(x-1, y, weight);
        }
        else{
            return Point(x, y, weight);
        }
    }

}
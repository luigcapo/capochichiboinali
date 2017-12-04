/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "PathMap.h"
#include "state/TerrainTypeId.h"
#include "state/Terrain.h"
#include <limits>

namespace ai{

    void PathMap::addSink(Point p) {
        weights[p.getX() + p.getY()*width] = 0;
        queue.push(p);
        
    }

    int PathMap::getWeight(const Point& p) const {
        if (p.getX() >= 0 && p.getY() >= 0 && p.getX() < width && p.getY() < height) {
            return weights[p.getX() + p.getY()*width];
        }
        else {
            return std::numeric_limits<int>::infinity();
        }
    }
    
    void PathMap::setWeight(const Point& p) {
        if (p.getX() >= 0 && p.getY() >= 0 && p.getX() < width && p.getY() < height) {
            weights[p.getX() + p.getY()*width] = p.getWeight();
        }
    }

    const std::vector<int>& PathMap::getWeights() const {
        return this->weights;
    }


    void PathMap::init(const state::ElementTab& grid) {
        this->width = grid.getWidth();
        this->height = grid.getHeight();
        
        weights.clear();
        // On redimmensionne la liste et on initialise ses éléments avec l'infini
        weights.resize(width*height, std::numeric_limits<int>::infinity());
    }
    
    /*Point PathMap::getWeightMin(int x, int y) const {
        if(x>0 && y>0 && x<width && y<height){
            if(weights[x+1, y] != std::numeric_limits<int>::infinity() && weights[x-1, y] != std::numeric_limits<int>::infinity()){
                if(weights[x-1, y] >= weights[x+i, y+j]){
                }
                else{
                }
            }
        }
    }*/

    Point PathMap::getWeightMax(int x, int y) const {
        
    }


    void PathMap::update(const state::ElementTab& grid) {
        /*
         * Dijkstra
         * 
         */
        static const std::vector<state::Direction> directions{
            state::Direction::EAST, state::Direction::NORTH,
            state::Direction::WEST, state::Direction::SOUTH_WEST,
            state::Direction::SOUTH, state::Direction::NORTH_EAST,
            state::Direction::NORTH_WEST, state::Direction::SOUTH_EAST};
            
        // queue.push(Point(0, 0, 0));
        
        while(!queue.empty()) {
            auto p = queue.top();
            queue.pop();
            setWeight(p);
            for(state::Direction d: directions) {
                auto pp = p.transform(d);
                // && state.getGrid().get(,)->getTypeId()==WALL (A ajouter quand on va ajouter WALL dans state)
                if(! (grid.get(p.getX(), p.getY())->getTypeId()==state::TypeId::TERRAIN) ){
                    auto e = grid.get(p.getX(), p.getY());
                    state::Terrain* t = (state::Terrain*)&e;
                    if(! (t->getTerrainTypeId() == state::TerrainTypeId::OCEAN) ){
                        pp.setWeight(p.getWeight() + 1);
                        if(getWeight(pp) > pp.getWeight()){
                            // setWeight(pp);
                            queue.push(pp);
                        }
                    }
                }
            }
        } // while
    } // update

}
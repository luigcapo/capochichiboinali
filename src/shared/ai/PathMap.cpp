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

    static const std::vector<state::Direction> directions{
            state::Direction::EAST, state::Direction::NORTH,
            state::Direction::WEST, state::Direction::SOUTH_WEST,
            state::Direction::SOUTH, state::Direction::NORTH_EAST,
            state::Direction::NORTH_WEST, state::Direction::SOUTH_EAST};
    
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


    void PathMap::init (state::State& state) {
        this->width = state.getTerrain().getWidth();
        this->height = state.getTerrain().getHeight();
        
        this->weights.clear();
        // On redimmensionne la liste et on initialise ses éléments avec l'infini
        this->weights.resize(this->width*this->height, std::numeric_limits<int>::infinity());
    }
    
    Point PathMap::getWeightMin(int x, int y) const {
        Point p(x, y, 0);
        Point min(x, y, 1);
        for(state::Direction d: directions){
           auto pp = p.transform(d);
           if(weights[pp.getX()+pp.getY()*width] <= weights[min.getX()+min.getY()*width]){
               min = pp;
           }
        }
        return min;
    }

    Point PathMap::getWeightMax(int x, int y) const {
        Point p(x, y, 0);
        Point max(x, y, 0);
        for(state::Direction d: directions){
            auto pp = p.transform(d);
            if(weights[pp.getX()+pp.getY()*width] > weights[max.getX()+max.getY()*width] ){
                if(weights[pp.getX()+pp.getY()*width] != std::numeric_limits<int>::infinity()){
                    max = pp;
                }
            }
        }
        return max;
    }


    void PathMap::update (state::State& state) {
        /*
         * Dijkstra
         * 
         */
        
        // queue.push(Point(0, 0, 0));
        while(!queue.empty()) {
            auto p = queue.top();
            queue.pop();
            setWeight(p);
            for(state::Direction d: directions) {
                auto pp = p.transform(d);
                auto e = state.getTerrain().get(p.getX(), p.getY());
                state::Terrain* t = (state::Terrain*)&e;
                // && state.getGrid().get(,)->getTypeId()==WALL (A ajouter quand on va ajouter WALL dans state)
                if(t->getTerrainTypeId() != state::TerrainTypeId::OCEAN){
                    pp.setWeight(p.getWeight() + 1);
                    if(getWeight(pp) > pp.getWeight()){
                        setWeight(pp);
                        queue.push(pp);
                    }
                }
            }
        } // while
    } // update

}
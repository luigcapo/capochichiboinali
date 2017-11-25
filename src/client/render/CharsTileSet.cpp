/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "CharsTileSet.h"
#include "state.h"

namespace render{

    CharsTileSet::CharsTileSet() {
        /*
         * 
         * military.push_back(Tile(0,100,10,10));military.push_back(Tile(30,100,10,10));millitary.push_back(Tile(60,100,10,10)); 
         * colon.push_back(Tile(80,100,10,10));
         * catapult.push_back(Tile(100,100,15,15));
         * 
         */
    }

    const std::string CharsTileSet::getImageFile() const {
        return "res/units_tileset.png";
    }

    int CharsTileSet::getCellWidth() const {
        return 768;
    }
    
    int CharsTileSet::getCellHeight() const {
        return 480;
    }  
    
    const Tile& CharsTileSet::getTile(const state::Element& e) const {
        
        if( e.isStatic() )
            return *( new Tile(0, 0, 0, 0) );
        
        else{
            
            // COLON
            if( e.getTypeId() == state::TypeId::COLON ){
                
                state::Colon* c = (state::Colon*)&e;
                //delete
                
                if( c->getOrientation() == state::Direction::NONE)
                    return *( new Tile(0, 0, 96, 96) );
                else if( c->getOrientation() == state::Direction::WEST)
                    return *( new Tile(0, 0, 96, 96) );
                else if( c->getOrientation() == state::Direction::NORTH_WEST)
                    return *( new Tile(96, 0, 96, 96) );
                else if( c->getOrientation() == state::Direction::NORTH)
                    return *( new Tile(192, 0, 96, 96) );
                else if( c->getOrientation() == state::Direction::NORTH_EAST)
                    return *( new Tile(288, 0, 96, 96) );
                else if( c->getOrientation() == state::Direction::EAST)
                    return *( new Tile(384, 0, 96, 96) );
                else if( c->getOrientation() == state::Direction::SOUTH_EAST)
                    return *( new Tile(480, 0, 96, 96) );
                else if( c->getOrientation() == state::Direction::SOUTH)
                    return *( new Tile(576, 0, 96, 96) );
                else if( c->getOrientation() == state::Direction::SOUTH_WEST)
                    return *( new Tile(672, 0, 96, 96) );
            }
            
            // MILITARY
            else if( e.getTypeId() == state::TypeId::MILITARY ){
                
                state::Military* m = (state::Military*)&e; 
                
                if( m->getMilTypeId() == state::MilTypeId::EPEISTE ){
                    
                    if( m->getOrientation() == state::Direction::NONE)
                        return *( new Tile(0, 96, 96, 96) );
                    else if( m->getOrientation() == state::Direction::WEST)
                        return *( new Tile(0, 96, 96, 96) );
                    else if( m->getOrientation() == state::Direction::NORTH_WEST)
                        return *( new Tile(96, 96, 96, 96) );
                    else if( m->getOrientation() == state::Direction::NORTH)
                        return *( new Tile(192, 96, 96, 96) );
                    else if( m->getOrientation() == state::Direction::NORTH_EAST)
                        return *( new Tile(288, 96, 96, 96) );
                    else if( m->getOrientation() == state::Direction::EAST)
                        return *( new Tile(384, 96, 96, 96) );
                    else if( m->getOrientation() == state::Direction::SOUTH_EAST)
                        return *( new Tile(480, 96, 96, 96) );
                    else if( m->getOrientation() == state::Direction::SOUTH)
                        return *( new Tile(576, 96, 96, 96) );
                    else if( m->getOrientation() == state::Direction::SOUTH_WEST)
                        return *( new Tile(672, 96, 96, 96) );
                }
                    
                else if( m->getMilTypeId() == state::MilTypeId::MITRAILLEUR ){
                    
                    if( m->getOrientation() == state::Direction::NONE)
                        return *( new Tile(0, 192, 96, 96) );
                    else if( m->getOrientation() == state::Direction::WEST)
                        return *( new Tile(0, 192, 96, 96) );
                    else if( m->getOrientation() == state::Direction::NORTH_WEST)
                        return *( new Tile(96, 192, 96, 96) );
                    else if( m->getOrientation() == state::Direction::NORTH)
                        return *( new Tile(192, 192, 96, 96) );
                    else if( m->getOrientation() == state::Direction::NORTH_EAST)
                        return *( new Tile(288, 192, 96, 96) );
                    else if( m->getOrientation() == state::Direction::EAST)
                        return *( new Tile(384, 192, 96, 96) );
                    else if( m->getOrientation() == state::Direction::SOUTH_EAST)
                        return *( new Tile(480, 192, 96, 96) );
                    else if( m->getOrientation() == state::Direction::SOUTH)
                        return *( new Tile(576, 192, 96, 96) );
                    else if( m->getOrientation() == state::Direction::SOUTH_WEST)
                        return *( new Tile(672, 192, 96, 96) );
                }
                
                else if( m->getMilTypeId() == state::MilTypeId::CATAPULT ){
                
                if( m->getOrientation() == state::Direction::NONE)
                    return *( new Tile(0, 384, 96, 96) );
                else if( m->getOrientation() == state::Direction::WEST)
                    return *( new Tile(0, 384, 96, 96) );
                else if( m->getOrientation() == state::Direction::NORTH_WEST)
                    return *( new Tile(96, 384, 96, 96) );
                else if( m->getOrientation() == state::Direction::NORTH)
                    return *( new Tile(192, 384, 96, 96) );
                else if( m->getOrientation() == state::Direction::NORTH_EAST)
                    return *( new Tile(288, 384, 96, 96) );
                else if( m->getOrientation() == state::Direction::EAST)
                    return *( new Tile(384, 384, 96, 96) );
                else if( m->getOrientation() == state::Direction::SOUTH_EAST)
                    return *( new Tile(480, 384, 96, 96) );
                else if( m->getOrientation() == state::Direction::SOUTH)
                    return *( new Tile(576, 384, 96, 96) );
                else if( m->getOrientation() == state::Direction::SOUTH_WEST)
                    return *( new Tile(672, 384, 96, 96) );
                }
                
                // MOUSQUETAIRE
                else{
                    if( m->getOrientation() == state::Direction::NONE)
                        return *( new Tile(0, 288, 96, 96) );
                    else if( m->getOrientation() == state::Direction::WEST)
                        return *( new Tile(0, 288, 96, 96) );
                    else if( m->getOrientation() == state::Direction::NORTH_WEST)
                        return *( new Tile(96, 288, 96, 96) );
                    else if( m->getOrientation() == state::Direction::NORTH)
                        return *( new Tile(192, 288, 96, 96) );
                    else if( m->getOrientation() == state::Direction::NORTH_EAST)
                        return *( new Tile(288, 288, 96, 96) );
                    else if( m->getOrientation() == state::Direction::EAST)
                        return *( new Tile(384, 288, 96, 96) );
                    else if( m->getOrientation() == state::Direction::SOUTH_EAST)
                        return *( new Tile(480, 288, 96, 96) );
                    else if( m->getOrientation() == state::Direction::SOUTH)
                        return *( new Tile(576, 288, 96, 96) );
                    else if( m->getOrientation() == state::Direction::SOUTH_WEST)
                        return *( new Tile(672, 288, 96, 96) );
                }
            }
            
        }
        return *( new Tile(0, 0, 0, 0) );
    }

    
    
}


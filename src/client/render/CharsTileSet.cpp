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
        return 512;
    }

    
    int CharsTileSet::getCellHeight() const {
        return 240;
    }

    
    
    const Tile& CharsTileSet::getTile(const state::Element& e) const {
        

        
        if( e.isStatic() )
            return *( new Tile(0, 0, 0, 0) );
        
        else{
            
            // COLON
            if( e.getTypeId() == 1 ){
                
                state::Colon* c = (state::Colon*)&e;
                //delete
                
                if( c->getOrientation() == state::NONE)
                    return *( new Tile(0, 0, 64, 48) );
                else if( c->getOrientation() == state::EAST)
                    return *( new Tile(0, 0, 64, 48) );
                else if( c->getOrientation() == state::NORTH)
                    return *( new Tile(64, 0, 64, 48) );
                else if( c->getOrientation() == state::WEST)
                    return *( new Tile(128, 0, 64, 48) );
                else if( c->getOrientation() == state::SOUTH)
                    return *( new Tile(192, 0, 64, 48) );
                else if( c->getOrientation() == state::NORTH_EAST)
                    return *( new Tile(256, 0, 64, 48) );
                else if( c->getOrientation() == state::NORTH_WEST)
                    return *( new Tile(328, 0, 64, 48) );
                else if( c->getOrientation() == state::SOUTH_EAST)
                    return *( new Tile(384, 0, 64, 48) );
                else if( c->getOrientation() == state::SOUTH_WEST)
                    return *( new Tile(448, 0, 64, 48) );
            }
            
            // MILITARY
            else if( e.getTypeId() ==2 ){
                
                state::Military* m = (state::Military*)&e;
                
                
                if( m->getMilTypeId() == state::EPEISTE ){
                    
                    if( m->getOrientation() == state::NONE)
                        return *( new Tile(0, 48, 64, 48) );
                    else if( m->getOrientation() == state::EAST)
                        return *( new Tile(0, 48, 64, 48) );
                    else if( m->getOrientation() == state::NORTH)
                        return *( new Tile(64, 48, 64, 48) );
                    else if( m->getOrientation() == state::WEST)
                        return *( new Tile(128, 48, 64, 48) );
                    else if( m->getOrientation() == state::SOUTH)
                        return *( new Tile(192, 48, 64, 48) );
                    else if( m->getOrientation() == state::NORTH_EAST)
                        return *( new Tile(256, 48, 64, 48) );
                    else if( m->getOrientation() == state::NORTH_WEST)
                        return *( new Tile(328, 48, 64, 48) );
                    else if( m->getOrientation() == state::SOUTH_EAST)
                        return *( new Tile(384, 48, 64, 48) );
                    else if( m->getOrientation() == state::SOUTH_WEST)
                        return *( new Tile(448, 48, 64, 48) );
                }
                    
                else if( m->getMilTypeId() == state::MITRAILLEUR ){
                    
                    if( m->getOrientation() == state::NONE)
                        return *( new Tile(0, 96, 64, 48) );
                    else if( m->getOrientation() == state::EAST)
                        return *( new Tile(0, 96, 64, 48) );
                    else if( m->getOrientation() == state::NORTH)
                        return *( new Tile(64, 96, 64, 48) );
                    else if( m->getOrientation() == state::WEST)
                        return *( new Tile(128, 96, 64, 48) );
                    else if( m->getOrientation() == state::SOUTH)
                        return *( new Tile(192, 96, 64, 48) );
                    else if( m->getOrientation() == state::NORTH_EAST)
                        return *( new Tile(256, 96, 64, 48) );
                    else if( m->getOrientation() == state::NORTH_WEST)
                        return *( new Tile(328, 96, 64, 48) );
                    else if( m->getOrientation() == state::SOUTH_EAST)
                        return *( new Tile(384, 96, 64, 48) );
                    else if( m->getOrientation() == state::SOUTH_WEST)
                        return *( new Tile(448, 96, 64, 48) );
                }
                
                else if( m->getMilTypeId() == state::CATAPULT ){
                
                if( m->getOrientation() == state::NONE)
                    return *( new Tile(0, 192, 64, 48) );
                else if( m->getOrientation() == state::EAST)
                    return *( new Tile(0, 192, 64, 48) );
                else if( m->getOrientation() == state::NORTH)
                    return *( new Tile(64, 192, 64, 48) );
                else if( m->getOrientation() == state::WEST)
                    return *( new Tile(128, 192, 64, 48) );
                else if( m->getOrientation() == state::SOUTH)
                    return *( new Tile(192, 192, 64, 48) );
                else if( m->getOrientation() == state::NORTH_EAST)
                    return *( new Tile(256, 192, 64, 48) );
                else if( m->getOrientation() == state::NORTH_WEST)
                    return *( new Tile(328, 192, 64, 48) );
                else if( m->getOrientation() == state::SOUTH_EAST)
                    return *( new Tile(384, 192, 64, 48) );
                else if( m->getOrientation() == state::SOUTH_WEST)
                    return *( new Tile(448, 192, 64, 48) );
                }
                
                // MOUSQUETAIRE
                else{
                    if( m->getOrientation() == state::NONE)
                        return *( new Tile(0, 144, 64, 48) );
                    else if( m->getOrientation() == state::EAST)
                        return *( new Tile(0, 144, 64, 48) );
                    else if( m->getOrientation() == state::NORTH)
                        return *( new Tile(64, 144, 64, 48) );
                    else if( m->getOrientation() == state::WEST)
                        return *( new Tile(128, 144, 64, 48) );
                    else if( m->getOrientation() == state::SOUTH)
                        return *( new Tile(192, 144, 64, 48) );
                    else if( m->getOrientation() == state::NORTH_EAST)
                        return *( new Tile(256, 144, 64, 48) );
                    else if( m->getOrientation() == state::NORTH_WEST)
                        return *( new Tile(328, 144, 64, 48) );
                    else if( m->getOrientation() == state::SOUTH_EAST)
                        return *( new Tile(384, 144, 64, 48) );
                    else if( m->getOrientation() == state::SOUTH_WEST)
                        return *( new Tile(448, 144, 64, 48) );
                }
            }
            
        }
        return *( new Tile(0, 0, 0, 0) );
    }

    
    
}


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "CharsTileSet.h"
#include "state.h"

namespace render{

    CharsTileSet::CharsTileSet() {
        for (int i=0;i<10;i++){
            for (int j=0;j<8;j++)
                unit.push_back(Tile(j*96,i*96,96,96));
        }
    }

    const std::string CharsTileSet::getImageFile() const {
        return "res/units_tileset.png";
    }

    int CharsTileSet::getCellWidth() const {
        return 768;
    }
    
    int CharsTileSet::getCellHeight() const {
        return 960;
    }  
    
    const Tile& CharsTileSet::getTile(const state::Element& e) const {
        
        if( e.isStatic() )
            return *(new Tile);
        else{
            /* COLON */
            if( e.getTypeId() == state::TypeId::COLON ){
                state::Colon* c = (state::Colon*)&e;
                state::Direction d = c->getOrientation();
                int j = c->getJ();
                j = j%2;
                
                switch(j){
                    case 0:
                        switch(d){
                            case state::Direction::NORTH_WEST:
                                return unit[1];
                            case state::Direction::NORTH:
                                return unit[2];
                            case state::Direction::NORTH_EAST:
                                return unit[3];
                            case state::Direction::EAST:
                                return unit[4];
                            case state::Direction::SOUTH_EAST:
                                return unit[5];
                            case state::Direction::SOUTH:
                                return unit[6];
                            case state::Direction::SOUTH_WEST:
                                return unit[7];
                            default: /* WEST & NONE*/
                                return unit[0];
                        }
                    case 1:
                        switch(d){
                            case state::Direction::NORTH_WEST:
                                return unit[41];
                            case state::Direction::NORTH:
                                return unit[42];
                            case state::Direction::NORTH_EAST:
                                return unit[43];
                            case state::Direction::EAST:
                                return unit[44];
                            case state::Direction::SOUTH_EAST:
                                return unit[55];
                            case state::Direction::SOUTH:
                                return unit[46];
                            case state::Direction::SOUTH_WEST:
                                return unit[47];
                            default: /* WEST & NONE*/
                                return unit[40];
                        }
                } /* switch joueur */
            }
            
            /* MILITARY */
            else if( e.getTypeId() == state::TypeId::MILITARY ){
                
                state::Military* m = (state::Military*)&e; 
                state::Direction d = m->getOrientation();
                state::MilTypeId r = m->getMilTypeId();
                
                int j = m->getJ();
                j = j%2;
                
                switch(j){
                    case 0:
                        switch(r){
                            case state::MilTypeId::EPEISTE:
                                switch(d){
                                    case state::Direction::NORTH_WEST:
                                        return unit[9];
                                    case state::Direction::NORTH:
                                        return unit[10];
                                    case state::Direction::NORTH_EAST:
                                        return unit[11];
                                    case state::Direction::EAST:
                                        return unit[12];
                                    case state::Direction::SOUTH_EAST:
                                        return unit[13];
                                    case state::Direction::SOUTH:
                                        return unit[14];
                                    case state::Direction::SOUTH_WEST:
                                        return unit[15];
                                    default: /* WEST & NONE*/
                                        return unit[8];
                                } /* switch Direction */
                            case state::MilTypeId::MITRAILLEUR:
                                switch(d){
                                    case state::Direction::NORTH_WEST:
                                        return unit[17];
                                    case state::Direction::NORTH:
                                        return unit[18];
                                    case state::Direction::NORTH_EAST:
                                        return unit[19];
                                    case state::Direction::EAST:
                                        return unit[20];
                                    case state::Direction::SOUTH_EAST:
                                        return unit[21];
                                    case state::Direction::SOUTH:
                                        return unit[22];
                                    case state::Direction::SOUTH_WEST:
                                        return unit[23];
                                    default: /* WEST & NONE*/
                                        return unit[16];
                                } /* switch Direction */
                            case state::MilTypeId::MOUSQUETAIRE:
                                switch(d){
                                    case state::Direction::NORTH_WEST:
                                        return unit[25];
                                    case state::Direction::NORTH:
                                        return unit[26];
                                    case state::Direction::NORTH_EAST:
                                        return unit[27];
                                    case state::Direction::EAST:
                                        return unit[28];
                                    case state::Direction::SOUTH_EAST:
                                        return unit[29];
                                    case state::Direction::SOUTH:
                                        return unit[30];
                                    case state::Direction::SOUTH_WEST:
                                        return unit[31];
                                    default: /* WEST & NONE*/
                                        return unit[24];
                                } /* switch Direction */
                            case state::MilTypeId::CATAPULT:
                                switch(d){
                                    case state::Direction::NORTH_WEST:
                                        return unit[33];
                                    case state::Direction::NORTH:
                                        return unit[34];
                                    case state::Direction::NORTH_EAST:
                                        return unit[35];
                                    case state::Direction::EAST:
                                        return unit[36];
                                    case state::Direction::SOUTH_EAST:
                                        return unit[37];
                                    case state::Direction::SOUTH:
                                        return unit[38];
                                    case state::Direction::SOUTH_WEST:
                                        return unit[39];
                                    default: /* WEST & NONE*/
                                        return unit[32];
                                } /* switch Direction */
                            default:
                                return *(new Tile);
                        } /* switch MilTypeId */
                    case 1:
                        switch(r){
                            case state::MilTypeId::EPEISTE:
                                switch(d){
                                    case state::Direction::NORTH_WEST:
                                        return unit[49];
                                    case state::Direction::NORTH:
                                        return unit[50];
                                    case state::Direction::NORTH_EAST:
                                        return unit[51];
                                    case state::Direction::EAST:
                                        return unit[52];
                                    case state::Direction::SOUTH_EAST:
                                        return unit[53];
                                    case state::Direction::SOUTH:
                                        return unit[54];
                                    case state::Direction::SOUTH_WEST:
                                        return unit[55];
                                    default: /* WEST & NONE*/
                                        return unit[48];
                                } /* switch Direction */
                            case state::MilTypeId::MITRAILLEUR:
                                switch(d){
                                    case state::Direction::NORTH_WEST:
                                        return unit[57];
                                    case state::Direction::NORTH:
                                        return unit[58];
                                    case state::Direction::NORTH_EAST:
                                        return unit[59];
                                    case state::Direction::EAST:
                                        return unit[60];
                                    case state::Direction::SOUTH_EAST:
                                        return unit[61];
                                    case state::Direction::SOUTH:
                                        return unit[62];
                                    case state::Direction::SOUTH_WEST:
                                        return unit[63];
                                    default: /* WEST & NONE*/
                                        return unit[56];
                                } /* switch Direction */
                            case state::MilTypeId::CATAPULT:
                                switch(d){
                                    case state::Direction::NORTH_WEST:
                                        return unit[65];
                                    case state::Direction::NORTH:
                                        return unit[66];
                                    case state::Direction::NORTH_EAST:
                                        return unit[67];
                                    case state::Direction::EAST:
                                        return unit[68];
                                    case state::Direction::SOUTH_EAST:
                                        return unit[69];
                                    case state::Direction::SOUTH:
                                        return unit[70];
                                    case state::Direction::SOUTH_WEST:
                                        return unit[71];
                                    default: /* WEST & NONE*/
                                        return unit[64];
                                } /* switch Direction */
                            case state::MilTypeId::MOUSQUETAIRE:
                                switch(d){
                                    case state::Direction::NORTH_WEST:
                                        return unit[73];
                                    case state::Direction::NORTH:
                                        return unit[74];
                                    case state::Direction::NORTH_EAST:
                                        return unit[75];
                                    case state::Direction::EAST:
                                        return unit[76];
                                    case state::Direction::SOUTH_EAST:
                                        return unit[77];
                                    case state::Direction::SOUTH:
                                        return unit[78];
                                    case state::Direction::SOUTH_WEST:
                                        return unit[79];
                                    default: /* WEST & NONE*/
                                        return unit[72];
                                } /* switch Direction */
                            default:
                                return *(new Tile);
                        } /* switch MilTypeId */
                } /* switch joueur */
            }
        }
        return *(new Tile);
    }
}

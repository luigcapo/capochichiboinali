/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "GridTileSet.h"
#include "state.h"

namespace render{

    GridTileSet::GridTileSet() {
        
        /*
         * 
         * plateau.push_back(Tile());plateau.push_back(Tile(0,10,24,24));plateau.push_back(Tile(0,20,24,24));plateau.push_back(Tile(0,40,24,24));plateau.push_back(Tile(0,50,24,24));plateau.push_back(Tile(0,80,24,24)); 
         * ressource.push_back(Tile(0,30,10,10));ressource.push_back(Tile(30,30,10,10));ressource.push_back(Tile(60,30,10,10));ressource.push_back(Tile(90,30,10,10));
         * wall.push_back(Tile(10,10,50,50));wall.push_back(Tile(20,20,50,50));
         * batiment.push_back(Tile(0,50,20,20));batiment.push_back(Tile(20,50,20,20));batiment.push_back(Tile(40,50,20,20));batiment.push_back(Tile(60,50,20,20));batiment.push_back(Tile(80,50,20,20));batiment.push_back(Tile(100,50,20,20));
         * 
         */
    }

    const std::string GridTileSet::getImageFile() const {
        return "res/grid_tileset.png";
    }

    int GridTileSet::getCellWidth() const {
        return 768;
    }

    int GridTileSet::getCellHeight() const {
        return 576;
    }


    const Tile& GridTileSet::getTile(const state::Element& e) const {
        
        // Définitition des tuiles éléments statiques
        
        // on teste si l'élément n'est pas mobile
        if( !(e.isStatic()) ){
            return *(new Tile);
        }
        
        // si l'élément est bien statique, on détermine son type afin de renvoyer la définition correspondante
        else{
            
            // mur
            if ( e.getTypeId()==4 ){ 
                
                state::Wall* w = (state::Wall*)&e;
                
                if( w->getWallTypeId() == state::WALLNORMAL )
                    return *( new Tile(576, 480, 96, 96) );
                else if( w->getWallTypeId() == state::WALLOFBABYLON )
                    return *( new Tile(576, 480, 96, 96) ); 
            }
            
            // plateau
            else if ( e.getTypeId() == 5 ){
                
                state::Plateau* p = (state::Plateau*)&e;
                
                if( p->getPlateautypeId() == state::EMPTY )
                    return *(new Tile);
                else if( p->getPlateautypeId() == state::PLAINE )
                    return *( new Tile(0, 0, 96, 48) );
                else if( p->getPlateautypeId() == state::COTE )
                    return *( new Tile(288, 384, 96, 48) );
                else if( p->getPlateautypeId() == state::DESERT )
                    return *( new Tile(288, 0, 96, 48) );
                else if( p->getPlateautypeId() == state::MONTAGNE )
                    return *( new Tile(0, 144, 96, 48) );
                else // ocean
                    return *( new Tile(0, 384, 96, 48) );
            }
            
            // ressource
            else if ( e.getTypeId() == 6 ){
                
                state::Ressource* r = (state::Ressource*)&e;
                
                if( r->getRessourceTypeId() == state::CHEVAL )
                    return *(new Tile);
                else if( r->getRessourceTypeId() == state::CHARBON )
                    return *(new Tile);
                else if( r->getRessourceTypeId() == state::FER )
                    return *(new Tile);
                else // vin
                    return *(new Tile);
            }
            
            // batiment
            else{
                
                state::Batiment* b = (state::Batiment*)&e;
                
                if( b->getBatimentTypeId() == state::WATER_MILL)
                    return *( new Tile(0, 480, 96, 96) );
                else if( b->getBatimentTypeId() == state::STONEHENGE )
                    return *( new Tile(96, 480, 96, 96) );
                else if( b->getBatimentTypeId() == state::SHRINE )
                    return *( new Tile(192, 480, 96, 96) );
                else if( b->getBatimentTypeId() == state::PYRAMID )
                    return *( new Tile(288, 480, 96, 96) );
                else if( b->getBatimentTypeId() == state::HANGING_GARDEN )
                    return *( new Tile(384, 480, 96, 96) );
                else if( b->getBatimentTypeId() == state::GRANARY )
                    return *( new Tile(480, 480, 96, 96) );
                else // BARRACK
                    return *( new Tile(576, 480, 96, 96) );
            } 
        }
        return *(new Tile);
    }
    

}
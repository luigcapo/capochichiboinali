/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "GridTileSet.h"
#include "state.h"

namespace render{

    GridTileSet::GridTileSet() {
        plateau.push_back(Tile());plateau.push_back(Tile());plateau.push_back(Tile());plateau.push_back(Tile());plateau.push_back(Tile());plateau.push_back(Tile()); 
        ressource.push_back(Tile());ressource.push_back(Tile());ressource.push_back(Tile());ressource.push_back(Tile());
        wall.push_back(Tile());wall.push_back(Tile());
        batiment.push_back(Tile());batiment.push_back(Tile());batiment.push_back(Tile());batiment.push_back(Tile());batiment.push_back(Tile());
    }


    const std::string GridTileSet::getImageFile() const {
        std::string s = "res/.jpg";
        return s;
    }

    const Tile& GridTileSet::getTile(const state::Element& e) const {
        if(!(e.isStatic())){return *(new Tile);}
        else{
            if (e.getTypeId()==4){
                state::Wall * w = (state::Wall*)&e;
                //if(e == w){return wall[1];}
                if(w->getWallTypeId() ==state::WALLNORMAL){return wall[2];}
                else if(w->getWallTypeId()==state::WALLOFBABYLON){return wall[1];}
            }
            else if (e.getTypeId()==6){
                state::Ressource*r= (state::Ressource*)&e;
                if(r->getRessourceTypeId() ==state::CHEVAL){return ressource[1];}
                else if(r->getRessourceTypeId()==state::CHARBON){return ressource[2];}
                else if(r->getRessourceTypeId()==state::FER){return ressource[3];}
                else {return ressource[4];}
            }
            else if (e.getTypeId()==5){
                state::Plateau*p= (state::Plateau*)&e;
                if(p->getPlateautypeId()==state::EMPTY){return plateau[1];}
                else if(p->getPlateautypeId()==state::PLAINE){return plateau[2];}
                else if(p->getPlateautypeId()==state::COTE){return plateau[3];}
                else if(p->getPlateautypeId()==state::DESERT){return plateau[4];}
                else if(p->getPlateautypeId()==state::MONTAGNE){return plateau[5];}
                else{return plateau[6];}
            }
            else{}//Refaire la liaison batiment colonie dans le state    
        }
        
    }
    

}
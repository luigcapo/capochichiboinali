/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "GridTileSet.h"
#include "state.h"

namespace render{

    GridTileSet::GridTileSet() {
        plateau.push_back(Tile());plateau.push_back(Tile(0,10,24,24));plateau.push_back(Tile(0,20,24,24));plateau.push_back(Tile(0,40,24,24));plateau.push_back(Tile(0,50,24,24));plateau.push_back(Tile(0,80,24,24)); 
        ressource.push_back(Tile(0,30,10,10));ressource.push_back(Tile(30,30,10,10));ressource.push_back(Tile(60,30,10,10));ressource.push_back(Tile(90,30,10,10));
        wall.push_back(Tile(10,10,50,50));wall.push_back(Tile(20,20,50,50));
        batiment.push_back(Tile(0,50,20,20));batiment.push_back(Tile(20,50,20,20));batiment.push_back(Tile(40,50,20,20));batiment.push_back(Tile(60,50,20,20));batiment.push_back(Tile(80,50,20,20));batiment.push_back(Tile(100,50,20,20));
    }


    const std::string GridTileSet::getImageFile() const {
        std::string s = "res/terrain1.jpg";
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
            else{
                state::Batiment*b=(state::Batiment*)&e;
                if(b->getBatimentTypeId()==state::BARAQUE){return batiment[1];}
                else if(b->getBatimentTypeId()==state::BIBLIOTHEQUE){return batiment[2];}
                else if(b->getBatimentTypeId()==state::AMPHITHEATRE){return batiment[3];}
                else if(b->getBatimentTypeId()==state::HOTEL){return batiment[4];}
            }//Refaire la liaison batiment colonie dans le state    
        }
        
    }
    

}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ElementTab.h"
#include "Utils.h"
#include "Terrain.h"
#include "TerrainTypeId.h"
#include "Batiment.h"
#include "PaysageTypeId.h"
#include "Paysage.h"

namespace state{
    
    ElementTab::ElementTab() {
        this->width = 0;
        this->height = 1;
    }
    
    ElementTab::ElementTab(int width, int height) {
        this->width = width;
        this->height = height;
        list.resize(width*height);
    }
    
    std::size_t ElementTab::getWidth () const {
        return this->width;
    }
    
    std::size_t ElementTab::getHeight () const {
        return this->height;
    }

    void ElementTab::add (Element* e) {
        list.push_back(std::unique_ptr<state::Element>(e));
    }
    
    Element* ElementTab::get (std::size_t i, std::size_t j) const {
        return list[i+j*width].get();
    }
    
    // permet de récupérer l'élément pointé puis de libérer l'espace mémoire
    Element* ElementTab::release(std::size_t i, std::size_t j) {
        return list[i+j*width].release();
    }


    void ElementTab::set (std::size_t i, std::size_t j, Element* e) {
        list[i+j*width].reset(e);
        
        if(e){
            e->setX(i);
            e->setY(j);
        }
    }
    
    std::size_t ElementTab::size () const{
        return list.size();   
    }
    
    
    void ElementTab::resize (std::size_t width, std::size_t height) {
        
        this->width = width;
        this->height = height;
        list.resize(width*height);
    }   
    
    void ElementTab::load(const std::string& file, int id) {
        
        // id=1 pour remplir la liste de terrain
        // id=2 pour la grille
        
        std::vector<int> map = loadCSV(file);
            
        int dimX = getDimentionsCSV(file)[0];
        int dimY = getDimentionsCSV(file)[1];
        
        this->resize(dimX, dimY);
        
        
        // case id = terrain
        if( id == 1){
            for(int i = 0; i < dimX; i++)
                for(int j = 0; j < dimY; j++){
                
                
                
                    switch ( map[i+j*dimX] ) {
                
                        case 0:
                            this->set(i, j, new Terrain(PLAINE));
                            break;
                        case 1:
                            this->set(i, j, new Terrain(DESERT));
                            break;
                        case 2:
                            this->set(i, j, new Terrain(NEIGE));
                            break;
                        /*case 3:
                            this->set(i, j, new Terrain());*/
                        case 4:
                            this->set(i, j, new Terrain(MOUNTAIN));
                            break;
                        default:
                            this->set(i, j, nullptr);
                            break;
                    }   // switch                   
                }
        }       
        
        // case id = grille
        else if(id == 2){
            
            for(int i = 0; i < dimX; i++)
                for(int j = 0; j < dimY; j++){
                    switch ( map[i+j*dimX] ) {
                        case 0:
                            this->set(i, j, new Paysage(FORET1));
                            break;
                        case 1:
                            this->set(i, j, new Paysage(FORET2));
                            break;
                        case 2:
                            this->set(i, j, new Paysage(PLANTE1));
                            break;
                        /*case 3:
                            this->set(i, j, NULL);
                        case 4:
                            this->set(i, j, NULL);
                        case 5:
                            this->set(i, j, NULL);
                        case 6:
                            this->set(i, j, NULL);
                        case 7:
                            this->set(i, j, NULL);
                        case 8:
                            this->set(i, j, NULL);
                        case 9:
                            this->set(i, j, NULL);
                        case 10:
                            this->set(i, j, NULL);*/
                        case 11:
                            this->set(i, j, new Paysage(COLLINE1));
                            break;
                        /*case 12:
                            this->set(i, j, NULL);
                        case 13:
                            this->set(i, j, NULL);
                        case 14:
                            this->set(i, j, NULL);
                        case 15:
                            this->set(i, j, NULL);
                        case 16:
                            this->set(i, j, NULL);*/
                        case 17:
                            this->set(i, j, new Paysage(MONTAGNE1));
                            break;
                        /*case 18:
                            this->set(i, j, NULL);
                        case 19:
                            this->set(i, j, NULL);
                        case 20:
                            this->set(i, j, NULL);
                        case 21:
                            this->set(i, j, NULL);
                        case 22:
                            this->set(i, j, NULL);
                        case 23:
                            this->set(i, j, NULL);*/
                        case 24:
                            this->set(i, j, new Batiment(WATER_MILL));
                            break;
                        case 25:
                            this->set(i, j, new Batiment(SHRINE));
                            break;
                        case 26:
                            this->set(i, j, new Batiment(PYRAMID));
                            break;
                        case 27:
                            this->set(i, j, new Batiment(PALACE));
                            break;
                        case 28:
                            this->set(i, j, new Batiment(LIBRARY));
                            break;
                        case 29:
                            this->set(i, j, new Batiment(GRANARY));
                            break;
                        case 30:
                            this->set(i, j, new Batiment(BARRACK));
                            break;
                        case 31:
                            this->set(i, j, new Batiment(HANGING_GARDEN));
                            break;
                        /*case 32:
                            this->set(i, j, NULL);
                        case 33:
                            this->set(i, j, NULL);
                        case 34:
                            this->set(i, j, NULL);
                        case 35:
                            this->set(i, j, NULL);
                        case 36:
                            this->set(i, j, NULL);
                        case 37:
                            this->set(i, j, NULL);
                        case 38:
                            this->set(i, j, NULL);
                        case 39:
                            this->set(i, j, NULL);
                        case 40:
                            this->set(i, j, NULL);
                        case 41:
                            this->set(i, j, NULL);
                        case 42:
                            this->set(i, j, NULL);
                        case 43:
                            this->set(i, j, NULL);
                        case 44:
                            this->set(i, j, NULL);
                        case 45:
                            this->set(i, j, NULL);
                        case 46:
                            this->set(i, j, NULL);
                        case 47:
                            this->set(i, j, NULL);
                        case 48:
                            this->set(i, j, NULL);
                        case 49:
                            this->set(i, j, NULL);
                        case 50:
                            this->set(i, j, NULL);
                        case 51:
                            this->set(i, j, NULL);
                        case 52:
                            this->set(i, j, NULL);
                        case 53:
                            this->set(i, j, NULL);
                        case 54:
                            this->set(i, j, NULL);
                        case 55:
                            this->set(i, j, NULL);
                        case 56:
                            this->set(i, j, NULL);
                        case 57:
                            this->set(i, j, NULL);
                        case 58:
                            this->set(i, j, NULL);
                        case 59:
                            this->set(i, j, NULL);
                        case 60:
                            this->set(i, j, NULL);
                        case 61:
                            this->set(i, j, NULL);
                        case 62:
                            this->set(i, j, NULL);
                        case 63:
                            this->set(i, j, NULL);
                        case 64:
                            this->set(i, j, NULL);
                        case 65:
                            this->set(i, j, NULL);
                        case 66:
                            this->set(i, j, NULL);
                        case 67:
                            this->set(i, j, NULL);
                        case 68:
                            this->set(i, j, NULL);
                        case 69:
                            this->set(i, j, NULL);
                        case 70:
                            this->set(i, j, NULL);*/
                        default:
                            this->set(i, j, nullptr);
                            break;
                    }   // switch
                        
                }
        }
    }   // load
        
        
}

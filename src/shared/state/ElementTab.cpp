/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ElementTab.h"
#include "Utils.h"

namespace state{
    
    ElementTab::ElementTab() {
        this->width = 0;
        this->height = 1;
        this->map1 = true;
    }
    
    ElementTab::ElementTab(int width, int height) {
        this->width = width;
        this->height = height;
        this->map1 = true;
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

    void ElementTab::set (std::size_t i, std::size_t j, Element* e) {
        list[i+j*width] = std::unique_ptr<state::Element>(e);
        e->setX(i);
        e->setY(j);
    }
    
    std::size_t ElementTab::size () const{
        return list.size();   
    }
    
    void ElementTab::resize (std::size_t width, std::size_t height) {
        
        this->width = width;
        this->height = height;
        list.resize(width*height);
    }
    void ElementTab::load(const std::string& file) {
        std::vector<int> vcarteInit = loadCSV(file);
        std::vector<int> tileToElem = loadCSV("res/TileToElement.csv");
            
        /*for(int i = 0; i<height; i++)
            for(int j = 0; j<width; j++){

                if(vcarteInit[i*width + j] < 0){
                    this->set(j,i,NULL);
                }
                else if(tileToElem[vcarteInit[i*width + j]] == 0){
                    this->set(j,i,(new Landscape(vcarteInit[i*width + j], false)));
                }
                else if(tileToElem[vcarteInit[i*width + j]] == 1){
                    this->set(j,i,(new Landscape(vcarteInit[i*width + j], true)));

                }
                else if(tileToElem[vcarteInit[i*width + j]] == 2){
                    this->set(j,i,(new City(1,true)));
                }
                else if(tileToElem[vcarteInit[i*width + j]] == 3)
                    this->set(j,i,(new City(1,false)));
                else if(tileToElem[vcarteInit[i*width + j]] == 4)
                    this->set(j,i,(new City(2,false))); 
                else if(tileToElem[vcarteInit[i*width + j]] == 5)
                    this->set(j,i,(new City(3,false)));
                else if(tileToElem[vcarteInit[i*width + j]] == -1){
                    this->set(j,i,NULL);
                }
                else
                    std::cout << "Erreur: tuile inutilisée" << std::endl;    
        }*/
    }

    Element* ElementTab::getChar (int i) const {
        return list[i].get();
    }
    void ElementTab::setChar(int i, Element* e) {
        list[i] = std::unique_ptr<state::Element>(e);
    }
    
    bool ElementTab::getMap1 () const {
        return this->map1;
    }

    void ElementTab::setMap2() {
        this->map1 = false;
    }


}

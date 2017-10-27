/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ElementTab.h"

namespace state{
    
    ElementTab::ElementTab() {
        width = 0;
        height = 1;
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
        //list[i+j*width] = e.set();
        list[i+j*width] = std::unique_ptr<state::Element>(e);
    }
    
    std::size_t ElementTab::size () const{
        return list.size();   
    }
    
    void ElementTab::resize (std::size_t width, std::size_t height){
        
        this->width = width;
        this->height = height;
        
        std::size_t taille = width+width*height;
        
        //Redimensionnement de la taille de la liste
        if( taille > list.size() ){
            
            do{
                list.push_back( nullptr );
            } while( taille > list.size() );   
        }
        else if( taille < list.size() ){
            
            do{
                list.pop_back();
            } while( taille < list.size() );
        }
        
        
        
    }
    

}

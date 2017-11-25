/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Utils.h"

using namespace std;



std::vector<int> loadCSV(const std::string fileName){
    
    std::vector<int> vcarte;
    std::string ligne,valeur;
    
    /* classe pour ouvrir des fichiers: ifstream (Input File stream) pour la
     * lecture et ofstream (Output File stream) pour l'écriture */
    
    std::ifstream fichier;
    fichier.open(fileName, ios::in);  // on ouvre le fichier en lecture   
    
    int sizeX = 0;
    int sizeY = 0;
        
    while(!fichier.eof()) {
        getline(fichier,ligne);
        stringstream stream(ligne);
            
        sizeX = 0;
        sizeY++;

        while(getline(stream, valeur,',')){	
            vcarte.push_back(atoi(valeur.c_str()));
            sizeX++;
        }
    }
        return vcarte;
}



vector<int> getDimentionsCSV(const std::string fileName){
    
    vector<int> vcarte, dimensions;
    ifstream fichier;
    fichier.open(fileName, std::ios::in);
    string ligne,valeur;
        
    int sizeY = 0;
    int sizeX = 0;
    int sizeTot = 0;
       		
    while(!fichier.eof()){
        getline(fichier,ligne);
        stringstream stream(ligne);
            
        sizeY++;

        while(getline(stream, valeur,',')){	
            sizeTot++;
        }            
    }
        
    sizeY--;
    sizeX = sizeTot / sizeY;
        
    dimensions.push_back(sizeX);
    dimensions.push_back(sizeY);        
    return dimensions;  
}
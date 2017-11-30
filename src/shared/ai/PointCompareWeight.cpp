/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "PointCompareWeight.h"
#include "Point.h"

namespace ai{

    // Fonction de comparaison : classe avec opérateur() qui renvoie true/false
    bool PointCompareWeight::operator()(const Point& a, const Point& b) {
        return a.getWeight() < b.getWeight() ;
    }

}
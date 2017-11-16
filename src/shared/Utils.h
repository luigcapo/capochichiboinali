/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

std::vector<int> loadCSV(const std::string fileName);
std::vector<int> getDimentionsCSV(const std::string fileName);

#endif /* UTILS_H */


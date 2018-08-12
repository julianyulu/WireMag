// biotSavartLaw.cc --- 
// 
// Filename: biotSavartLaw.cc
// Description: 
// 
// Author:    Yu Lu
// Email:     yulu@utexas.edu
// Github:    https://github.com/SuperYuLu 
// 
// Created: Sat Aug 11 21:16:24 2018 (-0500)
// Version: 
// Last-Updated: Sun Aug 12 00:17:58 2018 (-0500)
//           By: yulu
//     Update #: 26
// 

#include <iostream>
#include "biotSavartLaw.h"

BiotSavartLaw :: BiotSavartLaw(void){}

BiotSavartLaw :: BiotSavartLaw(const listVect *wireList){wires.push_back(wireList);}


void BiotSavartLaw :: addWires(const listVect *wireList){wires.push_back(wireList);}

void BiotSavartLaw :: clear(void);

//std::vector<double> BiotSavartLaw :: singlePointBField

// test.cc --- 
// 
// Filename: test.cc
// Description: 
// 
// Author:    Yu Lu
// Email:     yulu@utexas.edu
// Github:    https://github.com/SuperYuLu 
// 
// Created: Mon Aug 20 12:09:07 2018 (-0500)
// Version: 
// Last-Updated: Thu Aug 23 10:29:45 2018 (-0500)
//           By: yulu
//     Update #: 181
// 

#include "main.h"

int main(){

  // Generate and save grid points 
  Grid g;
  g.grid = *g.rectanglePlane();
  g.save();
  /*
  std::ofstream f1("grid.dat", std::ios::out);
  if (f1.is_open()){
    writeVectorList(f1, g.grid);
    f1.close();
  }
  */
  
  // Generate and save wire geometry
  Wire w;
  w.path = *w.solenoidPath();
  w.unit_length = 0.05;
  w.pathDiscretize();
  w.save();

  /*
  std::ofstream f2("wire_path.dat", std::ios::out);
  if (f2.is_open()){
    writeVectorList(f2, w.path);
    f2.close();
  }
  */

  // Calculate under biotSavartLaw 
  BiotSavartLaw bst;
  bst.addWires(&w);
  bst.mesh = &g;
  bst.current = 500;
  
  bst.meshGridBField();

  
  std::ofstream f3("B_field.dat", std::ios::out);
  if (f3.is_open()){
    writeVectorList(f3, *bst.magField);
    f3.close();
  }

  return 0;
}

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
// Last-Updated: Sat Aug 25 13:07:09 2018 (-0500)
//           By: yulu
//     Update #: 196
// 

#include "main.h"

int main(){
  // Generate and save wire geometry
  Wire w;
  w.path = *w.solenoidPath();
  w.unit_length = 0.05;
  w.pathDiscretize();
  w.save();
  
  // Generate and save grid points 
  Grid g;
  g.grid = *g.rectanglePlane();
  g.save();
  
  // Calculate under biotSavartLaw 
  BiotSavartLaw bst;
  bst.addWires(&w);
  bst.mesh = &g;
  bst.current = 500;
  bst.meshGridBField();

  // Prepare for output
  Field fd;
  fd.grid = &g.grid;
  fd.field = bst.magField;
  fd.scalarField();
  fd.sliceZ(0);
  fd.save();
  
  
  return 0;
}

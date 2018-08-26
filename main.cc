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
// Last-Updated: Sun Aug 26 12:55:39 2018 (-0500)
//           By: yulu
//     Update #: 231
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
  Mesh m;
  m.genMesh(-1, -1, -1, 1, 1, 1,  0.2);
  m.save();
  
  // Calculate under biotSavartLaw 
  BiotSavartLaw bst;
  bst.addWires(&w);
  bst.mesh = &m;
  bst.current = 500;
  bst.calculate();
  
  bst.startAnalysis();
  bst.sliceMeshZ(0);
  bst.normField();
  bst.saveAsCSV();
    
  return 0;
}

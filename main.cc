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
// Last-Updated: Wed Aug 29 23:57:40 2018 (-0500)
//           By: yulu
//     Update #: 248
// 

#include "main.h"

int main(){
  // Generate and save wire geometry
  Wire w;
  w.path = *w.solenoidPath(5.1e-3, 0.405e-3, 4, 2, 10);
  w.pathTranslate(0, 0, -0.25e-3);
  w.unit_length = 2e-3;
  w.pathDiscretize();
  w.save();

  // Generate and save grid points 
  Mesh m;
  m.genMesh(0, -5e-3,  -5e-3, 0, 5e-3,  5e-3, 0.1e-3);
  m.save();
  
  // Calculate under biotSavartLaw 
  BiotSavartLaw bst;
  bst.addWires(&w);
  bst.mesh = &m;
  bst.current = 500;
  bst.calculate();
  
  bst.startAnalysis();
  //bst.sliceMeshX(0);
  bst.normField();
  bst.saveAsCSV();
    
  return 0;
}

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
// Last-Updated: Fri Aug 31 00:02:16 2018 (-0500)
//           By: yulu
//     Update #: 255
// 

#include "main.h"

int main(){
  // Generate and save wire geometry
  Wire w1;
  w1.path = *w1.solenoidPath(5.1e-3, 0.405e-3, 4, 2, 20);
  w1.pathTranslate(0, 0, -2.5e-3);
  w1.unit_length = 2e-3;
  w1.pathDiscretize();
  //w1.save();

  Wire w2;
  w2.path = *w2.solenoidPath(5.1e-3, 0.405e-3, 4, 2, 20);
  w2.pathTranslate(0, 0, 2.5e-3);
  w2.unit_length = 2e-3;
  w2.pathDiscretize();
  //w2.save();

  // Generate and save grid points 
  Mesh m;
  m.genMesh(0, -5e-3,  -5e-3, 0, 5e-3,  5e-3, 0.1e-3);
  m.save();
  
  // Calculate under biotSavartLaw 
  BiotSavartLaw bst;
  bst.addWires(&w1);
  bst.addWires(&w2);
  bst.mesh = &m;
  bst.current = 500;
  bst.calculate();
  bst.saveWires();
  
  bst.startAnalysis();
  //bst.sliceMeshX(0);
  bst.normField();
  bst.saveAsCSV();
    
  return 0;
}

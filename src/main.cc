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
// Last-Updated: Tue Apr  2 12:40:03 2019 (-0500)
//           By: yulu
//     Update #: 263
// 

#include "main.h"

int main(){
  // Generate and save wire geometry
  Wire w1;
  // Selenoid wire with (radius, pitch, layers, turns_per_layer, points_per_turn
  w1.path = *w1.solenoidPath(5.1e-3, 0.405e-3, 4, 2, 20); // default axis along Z
  // translate along z-axis by -2.5 mm 
  w1.pathTranslate(0, 0, -2.5e-3);
  // Paht discretize length 
  w1.unit_length = 2e-3;
  w1.pathDiscretize();
  //w1.save();

  Wire w2;
  w2.path = *w2.solenoidPath(5.1e-3, 0.405e-3, 4, 4, 20);
  w2.pathTranslate(0, 0, 2.5e-3);
  w2.unit_length = 2e-3;
  w2.pathDiscretize();
  //w2.save();

  // Generate and save grid points 
  Mesh m;
  // (x1,y1,z1, x2, y2, z2)
  m.genMesh(-5e-3, -5e-3,  -10e-3, 5e-3, 5e-3,  10e-3, 0.5e-3);
  m.save();
  
  // Calculate under biotSavartLaw 
  BiotSavartLaw bst;
  bst.addWires(&w1);
  bst.addWires(&w2);
  bst.mesh = &m;
  bst.current = 400;
  bst.calculate();
  bst.saveWires();
  
  bst.startAnalysis();
  //bst.sliceMeshX(0);
  bst.normField();
  bst.saveAsCSV();
    
  return 0;
}

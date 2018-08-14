// main.cc --- 
// 
// Filename: main.cc
// Description: 
// 
// Author:    Yu Lu
// Email:     yulu@utexas.edu
// Github:    https://github.com/SuperYuLu 
// 
// Created: Fri Aug 10 11:02:15 2018 (-0500)
// Version: 
// Last-Updated: Mon Aug 13 22:44:36 2018 (-0500)
//           By: yulu
e//     Update #: 48
// 

#include<list>
#include "vectorAddOns.h"
#include "wire.h"


int main(){
  
  listVect  p = {{1.0,2.0,3},{2, 3, 4}, {3, 4, 5}};
  
  Wire w(p, 0.5, 1);
  w.pathTranslate(std::vector<double> {10,10,10});
  w.pathRotate(std::vector<double> {0, 0, 1}, 90.0);

  listVect s = w.pathDiscretize();
  IdL_R IdLR = w.elementIdLR();

  
  
  std::cout << "dis path: " << std::endl;
  for(std::vector<double> x: s){
    printVector(x);
  }
  
  std::cout << "IdL: "<< std::endl;
  for(auto x: IdLR.IdL){
    printVector(x);
  }

  std::cout << "R: "<< std::endl;
  for(auto x: IdLR.R){
    printVector(x);
  }
  return 0;
}

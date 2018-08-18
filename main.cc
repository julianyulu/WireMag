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
// Last-Updated: Wed Aug 15 01:20:44 2018 (-0500)
//           By: yulu
//     Update #: 115
// 

#include "main.h"

int main(){

  Wire w;
  IdL_R IdLR;
  w.current = 100;
  w.unit_length = 0.1;
  std::vector<double> start = {0, 0, 0};
  std::vector<double> end = {0, 0, 1};
  vectorList * grid;
  vectorList *B;
  w.path = w.linearPath(start,  end);
  //w.path = w.rectangularPath(0.5, 1.0);
  IdLR = w.elementIdLR();
  grid = Grid().cuboidVolumn(-1, 1, -1, 1, -1, 1, 0.2);
  BiotSavartLaw bls(&w);
  B =  bls.calculateBField(*grid);
 
  std::cout << "path" << std::endl;
  for(std::vector<double> x: w.path){
    printVector(x);
  }


  std::cout << "B Field" << std::endl;
  for(std::vector<double> x: *B){
    printVector(x);
  }
  /*  
  std::cout << "grid" << std::endl;
  for(std::vector<double> x: *grid){
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
  */
  return 0;
}

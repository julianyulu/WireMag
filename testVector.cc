// testVector.cc --- 
// 
// Filename: testVector.cc
// Description: 
// 
// Author:    Yu Lu
// Email:     yulu@utexas.edu
// Github:    https://github.com/SuperYuLu 
// 
// Created: Wed Aug  8 23:14:01 2018 (-0500)
// Version: 
// Last-Updated: Sat Aug 11 12:37:45 2018 (-0500)
//           By: yulu
//     Update #: 22
// 
#include<iostream>
#include<vector>
#include "vectorAddOns.h"

int main(){
  std::vector<int> a(3, 10);
  std::vector<int> b(3, 5);
  std::vector<double> e(3, 5);
  std::vector<int> c = a + b;
  std::vector<double> d = e + double(3.14);
  std::vector<int> f = a * b;
  double norm = l2_norm(d);
  
  for(double x:c){
    std::cout << x << ' ';
  }
  std::cout << std::endl;
  
  for(double x:d){
    std::cout << x << ' ';
  }
  std::cout << std::endl;

  for(double x:f){
    std::cout << x << ' ';
  }
  std::cout << std::endl;
  
  std::cout << "L2 norm: " << norm << std::endl;
}

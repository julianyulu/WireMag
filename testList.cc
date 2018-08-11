// testList.cc --- 
// 
// Filename: testList.cc
// Description: 
// 
// Author:    Yu Lu
// Email:     yulu@utexas.edu
// Github:    https://github.com/SuperYuLu 
// 
// Created: Wed Aug  8 23:14:01 2018 (-0500)
// Version: 
// Last-Updated: Sat Aug 11 13:00:36 2018 (-0500)
//           By: yulu
//     Update #: 34
// 
#include<iostream>
#include<list>
#include "listAddOns.h"

int main(){
  std::list<int> a(3, 10);
  std::list<int> b(3, 5);
  std::list<double> e(3, 5);
  std::list<int> c = a + b;
  std::list<double> d = e + double(3.14);
  std::list<int> f = a * b;
  double norm = l2_norm(d);
  /*
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
  */

  for(std::list<int> ::iterator iter = a.begin(); iter != a.end(); iter ++){
    std::cout << *(iter + 1) << std::endl;
  }
  
  std::cout << std::endl;
  
  std::cout << "L2 norm: " << norm << std::endl;
}

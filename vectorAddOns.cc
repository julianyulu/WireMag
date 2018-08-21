// vectorAddOns.cc --- 
// 
// Filename: vectorAddOns.cc
// Description: 
// 
// Author:    Yu Lu
// Email:     yulu@utexas.edu
// Github:    https://github.com/SuperYuLu 
// 
// Created: Thu Aug  9 00:07:39 2018 (-0500)
// Version: 
// Last-Updated: Mon Aug 20 15:05:10 2018 (-0500)
//           By: yulu
//     Update #: 19
// 

#include "vectorAddOns.h"
#include <cmath>



std::ostream& writeVectorList(std::ostream& os, vectorList& v){
  for(auto x:v){
    for(auto y:x){
      os << y << "\t";
    }
    os << std::endl;
  }
  return os;
}


// l2 normalization of vector
// ------------------------------------------

double l2_norm(const std::vector<double>  &u){
    /* L2 norm of vector  */
    double accum = 0;
    for (double x:u){
      accum += x * x;
    }
    return std::sqrt(accum);
}

double l2_norm(const std::vector<int>  &u){
    /* L2 norm of vector  */
    double accum = 0;
    for (double x:u){
      accum += x * x;
    }
    return std::sqrt(accum);
}

double vector_dot(const std::vector<double> &u,const std::vector<double> &v){
  double sum = 0.0;
  for(double x: u * v){ sum += x;}
  return sum;
}


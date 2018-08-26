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
// Last-Updated: Sun Aug 26 13:00:49 2018 (-0500)
//           By: yulu
//     Update #: 26
// 

#include "vectorOperation.h"
#include <cmath>


// Write Vectorlist as output csv stream
std::ostream& writeVectorList(std::ostream& os, vectorList& v){
  for(auto x:v){
    for(auto y:x){
      if(y != x.back()){os << y << ",";}
      else{os << y << std::endl;}
    }
  }
  return os;
}

// Cross product of two vectors 
std::vector<double> crossProduct(const std::vector<double> &x,
				 const std::vector<double> &y){
  std::vector<double> product = {x[1] * y[2] - x[2] * y[1],
				 x[0] * y[2] - x[2] * y[0],
				 x[0] * y[1] - x[1] * y[0]};
  return product;
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


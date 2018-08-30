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
// Last-Updated: Wed Aug 29 23:27:51 2018 (-0500)
//           By: yulu
//     Update #: 35
// 

#include "vectorOperation.h"
#include <cmath>


// Write Vectorlist as output csv stream
std::ostream& writeVectorList(std::ostream& os, vectorList& v){
  int vectorSize = int(v.front().size());
  for(auto x:v){
    for(int i = 0; i < vectorSize; i++){
      if(i != vectorSize - 1 ) os << x[i] << ",";
      else{os << x[i] << std::endl;}
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


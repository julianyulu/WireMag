// vectorAddOns.cc --- 
// 
// Filename: vectorAddOns.cc
// Description: 
// 
// Author:    Yu Lu
// Email:     yulu@utexas.edu
// Github:    https://github.com/SuperYuLu 
// 
// Created: Wed Aug  8 22:29:28 2018 (-0500)
// Version: 
// Last-Updated: Mon Aug 20 15:04:25 2018 (-0500)
//           By: yulu
//     Update #: 98
// 

#ifndef _vectorAddOns_h_
#define _vectorAddOns_h_

#include<vector>
#include<list>
#include<algorithm>
#include<iostream>


typedef std::list< std::vector <double>> vectorList;

std::ostream& writeVectorList(std::ostream& os, vectorList& v);
  

// Auxxillary funcitions
template <typename T>
void printVector(std::vector<T> v){
  for(double x:v){
    std::cout << x << " ";
  }
  std:: cout << std::endl;
}

// Operator +
// -----------------------------
template <typename T>
std::vector<T> operator +(const std::vector<T> &a, const std::vector<T> &b){
  std::vector<T> res(a.size());
  if(a.size() != b.size()){
    //std::cout << "size a:" << a.size() << " size b: " << b.size() << std::endl;
    //printVector(a);
    std::cerr << "Vector operation '+' cannot be used for two vectors with different size"
	      << std::endl;
  }else{
    std::transform(a.begin(), a.end(), b.begin(), res.begin(), std::plus<T>());
  }
  
  //std::transform(a.begin(), a.end(), b.begin(), res.begin(), std::plus<T>());
  return res;
}

template <typename T>
std::vector<T> operator +(const std::vector<T> &a, const T &b){
  std::vector<T> res(a.size());
  std::transform(a.begin(), a.end(), res.begin(), [b](T x){return x + b;});
  return res;
}

template <typename T>
std::vector<T> operator +(const T &a, const std::vector<T> &b){
  std::vector<T> res(b.size());
  std::transform(b.begin(), b.end(), res.begin(), [a](T x){return x + a;});
  return res;
}

// Operator -
// -----------------------------
template <typename T>
std::vector<T> operator -(const std::vector<T> &a, const std::vector<T> &b){
  std::vector<T> res(a.size());
  if(a.size() != b.size()){
    std::cerr << "Vector operation '-' cannot be used for two vectors with different size"
	      << std::endl;
    
  }else{
    std::transform(a.begin(), a.end(), b.begin(), res.begin(), std::minus<T>());
  }
  return res;
}

template <typename T>
std::vector<T> operator -(const std::vector<T> &a, const T &b){
  std::vector<T> res(a.size());
  std::transform(a.begin(), a.end(), res.begin(), [b](T x){return x - b;});
  return res;
}

template <typename T>
std::vector<T> operator -(const T &a, const std::vector<T> &b){
  std::vector<T> res(b.size());
  std::transform(b.begin(), b.end(), res.begin(), [a](T x){return x - a;});
  return res;
}


// operator *
// ------------------------
template <typename T>
std::vector<T> operator *(const std::vector<T> &a, const std::vector<T> &b){
  std::vector<T> res(a.size());
  if(a.size() != b.size()){
    std::cerr << "Vector operation '*' cannot be used for two vectors with different size"
	      << std::endl;
  }else{
    std::transform(a.begin(), a.end(), b.begin(), res.begin(), std::multiplies<T>());
  }
  return res;
}
  
template <typename T>
std::vector<T> operator *(const std::vector<T> &a, const T &b){
  std::vector<T> res(a.size());
  std::transform(a.begin(), a.end(), res.begin(), [b](T x){return x * b;});
  return res;
}

template <typename T>
std::vector<T> operator *(const T &a, const std::vector<T> &b){
  std::vector<T> res(b.size());
  std::transform(b.begin(), b.end(), res.begin(), [a](T x){return x * a;});
  return res;
}


// operator /
// ------------------------
template <typename T>
std::vector<T> operator /(const std::vector<T> &a, const std::vector<T> &b){
  std::vector<T> res(a.size());
  if(a.size() != b.size()){
    std::cerr << "Vector operation '/' cannot be used for two vectors with different size"
	      << std::endl;
  }else{
    std::transform(a.begin(), a.end(), b.begin(), res.begin(), std::divides<T>());
  }
  return res;
}
  
template <typename T>
std::vector<T> operator /(const std::vector<T> &a, const T &b){
  std::vector<T> res(a.size());
  std::transform(a.begin(), a.end(), res.begin(), [b](T x){return x / b;});
  return res;
}

template <typename T>
std::vector<T> operator /(const T &a, const std::vector<T> &b){
  std::vector<T> res(b.size());
  std::transform(b.begin(), b.end(), res.begin(), [a](T x){return x / a;});
  return res;
}



double l2_norm(const std::vector<double>  &);
double l2_norm(const std::vector<int>  &);
double vector_dot(const std::vector<double> &, const std::vector<double> &);
    

#endif //_vectorAddOns_h_

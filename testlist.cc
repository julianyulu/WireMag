// testlist.cc --- 
// 
// Filename: testlist.cc
// Description: 
// 
// Author:    Yu Lu
// Email:     yulu@utexas.edu
// Github:    https://github.com/SuperYuLu 
// 
// Created: Sat Aug 11 12:08:29 2018 (-0500)
// Version: 
// Last-Updated: Sat Aug 11 12:20:30 2018 (-0500)
//           By: yulu
//     Update #: 12
// 

#include<list>
#include<algorithm>
#include<iostream>
typedef std::list< std::list <double>> list2;

template <typename T>
std::list<T> operator+(const std:: list<T> &a, const std::list<T> &b){
  std::list<T> res(a.size());
  std::transform(a.begin(), a.end(), b.begin(), res.begin(), std::plus<T>());
  return res;
}


int main(){
  list2 a = {{1,2,3}, {3,4,5}};
  list2 b = {{1,2,3}, {3,4,5}};
  std::list<double> c(a.size());
  c = a.front() + b.front();
  for(double x: c){
    std::cout<< x << " ";
  }
  std::cout << std::endl;
  return 0;
}

  

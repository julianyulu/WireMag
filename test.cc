// test.cc --- 
// 
// Filename: test.cc
// Description: 
// 
// Author:    Yu Lu
// Email:     yulu@utexas.edu
// Github:    https://github.com/SuperYuLu 
// 
// Created: Fri Aug 10 10:12:47 2018 (-0500)
// Version: 
// Last-Updated: Fri Aug 10 10:49:39 2018 (-0500)
//           By: yulu
//     Update #: 35
// 
#include<vector>
#include<iostream>
#include "vectorAddOns.h"

using namespace std;
typedef vector<vector < double>> vector2;
int main(){
  vector2 vec = {{1,2,3}, {4,5,6}};
  vector <double> a = {7,8,9};
  vector <double>* ptr;
  vector2::reverse_iterator riter;
  vector2::iterator iter;
  int x = 1;
  ptr = &a;
  riter = vec.rbegin();
  iter = vec.begin();
  //vec.insert(iter, *ptr);
  iter = vec.insert(iter,a);
  for (vector <double> x: vec){
    
    printVector(x);
    cout << endl;
  }

  cout << "iter again" << endl;
  printVector(*iter);

  
  return 0;
}

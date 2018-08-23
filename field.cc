// field.cc --- 
// 
// Filename: field.cc
// Description: 
// 
// Author:    Yu Lu
// Email:     yulu@utexas.edu
// Github:    https://github.com/SuperYuLu 
// 
// Created: Thu Aug 23 10:02:15 2018 (-0500)
// Version: 
// Last-Updated: Thu Aug 23 10:27:17 2018 (-0500)
//           By: yulu
//     Update #: 12
// 

#include "field.h"

Field :: Field(void){
  grid = 0;
  field = 0;
}

Field :: Field(vectorList* ptrGrid, vectorList* ptrFeild){
  grid = ptrGrid;
  field = ptrField;
}


std::list<double> * Field :: normField(const vectorList* inputField){
  static std::list<double> normedField;
  for(auto x : *inputField0){
    normedField.push_back(l2_norm(x));
  }
  return &normedField;
}

void Field :: save(void){
  std::ofstream f("field.dat", std::ios::out);
  if(f.is_open()){
    f << "#" << "x\t" << "y\t" << "z" << std::endl; //gnuplot comment
    writeVectorList(f, *field);
    f.close();
    std::cout << "Field data saved in file: " << "field.dat" << std::endl;
  }
}


  



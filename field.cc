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
// Last-Updated: Fri Aug 24 00:39:44 2018 (-0500)
//           By: yulu
//     Update #: 22
// 

#include "field.h"
#include <iostream>

Field :: Field(void){
  grid = 0;
  field = 0;
  sliced = {};
}

Field :: Field(vectorList* ptrGrid, vectorList* ptrFeild){
  grid = ptrGrid;
  field = ptrField;
  sliced = {};
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

/*
const vectorList* Field :: findSingleXYZ(char axis, double value){
  int colIdx;
  double minDiff;
  vectorList :: const_iterator pGrid;
  vectorList :: const_iterator pField;
  static vectorList :: resultList;

    
  switch(axis){
  case 'x': colIdx = 0;
  case 'y': colIdx = 1;
  case 'z': colIdx = 2;
  default:
    std::err << "Axis not understand, options: 'x', 'y', 'z'" << std::endl;
  }

  pGrid = grid -> begin();
  pField = field -> begin();

  minDiff = l2_norm(*pGrid - (*std::next(pGrid)));
  pGrid = grid -> begin();
    
  while(pGrid != grid -> end()){
    if(std :: abs((*pGrid)[colIdx] - value)) < minDiff{
	minDiff = std :: abs((*pGrid)[colIdx] - value);
	if(resultList.empty){
	  resultList.push_back((*pGrid)
*/
  
  


void Field :: sliceX(double x){
  



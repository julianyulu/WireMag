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
// Last-Updated: Sat Aug 25 13:09:39 2018 (-0500)
//           By: yulu
//     Update #: 76
// 

#include "field.h"
#include <iostream>

Field :: Field(void){
  grid = 0;
  field = 0;
  sliced = {};
}

Field :: Field(const vectorList* ptrGrid, const vectorList* ptrField){
  grid = ptrGrid;
  field = ptrField;
  sliced = *ptrField;
}


vectorList* Field :: normField(const vectorList* inputField){
  static vectorList normedField;
  normedField.clear();
  for(auto x : *inputField){
    normedField.push_back(std::vector<double>(l2_norm(x)));
  }
  return &normedField;
}

void Field :: scalarField(void){
  normalize = true;
}

void Field :: save(void){
  
  vectorList :: const_iterator pGrid;
  vectorList :: const_iterator pField;
  std::vector<double> conbineVector;

  pGrid = grid -> begin();
  pField = field -> begin();
  
  if(sliced.empty()){
    if(normalize){
      while(pGrid != grid -> end()){
	conbineVector = *pGrid;
	conbineVector.insert(conbineVector.end(), l2_norm(*pField));
	sliced.push_back(conbineVector);
	pGrid++;
	pField++;
      }
    }else{
      while(pGrid != grid -> end()){
	conbineVector = *pGrid;
	conbineVector.insert(conbineVector.end(), pField -> begin(), pField -> end());
	sliced.push_back(conbineVector);
	pGrid++;
	pField++;
      }
    }
  }
  
  std::ofstream f("field.dat", std::ios::out);
  if(f.is_open()){
    if(normalize){
      f << "#" << "x\t" << "y\t" << "z\t"
      << "Babs" << std::endl; //gnuplot comment
    }else{
      f << "#" << "x\t" << "y\t" << "z\t"
	<< "Bx\t" << "By\t" << "Bz" << std::endl; //gnuplot comment
    }
    writeVectorList(f, sliced);
    f.close();
    std::cout << "Field data saved in file: " << "field.dat" << std::endl;
  }
}


const vectorList* Field :: findSingleXYZ(char axis, double value){
  int colIdx;
  double minDiff;
  vectorList :: const_iterator pGrid;
  vectorList :: const_iterator pField;
  static vectorList resultList;
  std::vector<double> conbineVector;
  switch(axis){
  case 'x': colIdx = 0; break;
  case 'y': colIdx = 1; break;
  case 'z': colIdx = 2; break;
  default:
    std::cerr << "Axis not understand, options: 'x', 'y', 'z'" << std::endl;
  }

  pGrid = grid -> begin();
  pField = field -> begin();
  minDiff = l2_norm(*pGrid - (*std::next(pGrid)));

  while(pGrid != grid -> end()){
    if(std :: abs((*pGrid)[colIdx] - value) < minDiff / 2){
      if(normalize){
	conbineVector = *pGrid;
	conbineVector.insert(conbineVector.end(), l2_norm(*pField));
	resultList.push_back(conbineVector);
      }else{
	conbineVector = *pGrid;
	conbineVector.insert(conbineVector.end(), pField -> begin(), pField -> end());
	resultList.push_back(conbineVector);
      }
    }
    pGrid++;
    pField++;
  }
  
  if(resultList.empty()){
    std::cout << axis << " = " << value << " not found in the grid" << std::endl;
  }
  return &resultList; 
}


void Field :: sliceX(double x){
  sliced = *findSingleXYZ('x', x);
}

void Field :: sliceY(double y){
  sliced = *findSingleXYZ('y', y);
}

void Field :: sliceZ(double z){
  sliced = *findSingleXYZ('z', z);
}

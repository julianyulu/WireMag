// genGrid.cc --- 
// 
// Filename: genGrid.cc
// Description: 
// 
// Author:    Yu Lu
// Email:     yulu@utexas.edu
// Github:    https://github.com/SuperYuLu 
// 
// Created: Mon Aug 13 22:53:04 2018 (-0500)
// Version: 
// Last-Updated: Tue Aug 14 00:16:29 2018 (-0500)
//           By: yulu
//     Update #: 45


#include <cmath>
#include <vector>
#include <list>
#include "genGrid.h"

std::list<double>* Grid::gen1DGrid(double xBegin, double xEnd, double xResolution){
  double npts;
  static std::list<double> points;
  npts = std::ceil(std::abs(xBegin - xEnd) / xResolution);
  for(int i = 0; i < npts; i++){
    points.push_back(xBegin + i * xResolution);
  }
  if(points.back() != xEnd){
    points.push_back(xEnd);
  }
  return &points;
}


vectorList* Grid::meshGrid(const std::list<double> *xCoords, const std::list<double> *yCoords, const std::list<double> *zCoords){
  std::vector<double> point(3);
  static vectorList gridPoints;
  
  for(auto x: *xCoords){
    for(auto y: *yCoords){
      for(auto z: *zCoords){
	point = std::vector<double>({x, y, z});
	gridPoints.push_back(point);
      }
    }
  }
  return &gridPoints;
}


  
  
vectorList* Grid::cuboidVolumn(double x1, double x2, double y1, double y2, double z1, double z2, double resolution){
  // std::list<double> xCoords, yCoords, zCoords;
  return meshGrid(gen1DGrid(x1, x2, resolution),
		  gen1DGrid(y1, y2, resolution),
		  gen1DGrid(z1, z2, resolution));
}

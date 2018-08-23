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
// Last-Updated: Thu Aug 23 10:26:18 2018 (-0500)
//           By: yulu
//     Update #: 124


#include <cmath>
#include "genGrid.h"
#include <fstream>
#include <iostream>
Grid :: Grid(void){
  grid = vectorList({});
}

/* need enum, a bit tricky 
Grid:: Grid(std::string kind){
  enum KIND { point, line, 
  switch(kind){
  case "point": grid = singlePiont(); break;
  case "line": grid = line(); break;
  case "rectanglePlane": grid = rectanglePlane(); break;
  case "cuboidVolumn": grid = cuboidVolumn();
  default: grid = cuboidVolumn();
  }
}
*/  

void Grid :: save(void){
  std::ofstream f("grid.dat", std::ios::out);
  if(f.is_open()){
    f << "#" << "x\t" << "y\t" << "z" << std::endl; //gnuplot comment
    writeVectorList(f, grid);
    f.close();
    std::cout << "Grid data saved in file: " << "grid.dat" << std::endl;
  }
}



// Single point grid
vectorList* Grid ::  singlePiont(double x, double y, double z){
  static vectorList point = {{x, y, z}};
  return &point;
}


// Line grid
vectorList* Grid :: line(double x1, double y1, double z1,
			 double x2, double y2, double z2, double resolution){
  return meshGrid(gen1DGrid(x1, x2, resolution),
		  gen1DGrid(y1, y2, resolution),
		  gen1DGrid(z1, z2, resolution));
}


// Rectangle plane grid
vectorList* Grid :: rectanglePlane(double x1, double y1, double z1,
			    double x2, double y2, double z2, double resolution){
    return cuboidVolumn(x1, y1, z1, x2, y2, z2, resolution);
}


// Cuboid volumn gird
vectorList* Grid :: cuboidVolumn(double x1, double y1, double z1,
			  double x2, double y2, double z2, double resolution){
  
  return meshGrid(gen1DGrid(x1, x2, resolution),
		  gen1DGrid(y1, y2, resolution),
		  gen1DGrid(z1, z2, resolution));
}



//vectorList* Grid :: reduceDim(vectorList& input, int axis, double keep_value){}
  // reduce vectorList dimention along vector index 'axis', by slicing
  // at condition  vector[axis] = 'keep_value'
    


// Generate 1d meshgrid 
std::vector<double> Grid::gen1DGrid(double xBegin, double xEnd, double xResolution){
  
  double npts;
  static std::vector<double> points;
  points.clear();
  
  npts = std::ceil(std::abs(xEnd - xBegin) / xResolution);
  xResolution = (xEnd > xBegin)? std::abs(xResolution) : -std::abs(xResolution);
  if(npts == 0){
    points.push_back(xBegin);
  }else{
    for(int i = 0; i < npts; i++){
      points.push_back(xBegin + i * xResolution);
    }
  }
  
  if(points.back() !=  xEnd){
    points.push_back(xEnd);
  }

  return points;
}


// Overload meshGrid for both 2D and 3D cases 

vectorList* Grid::meshGrid(const std::vector<double> xCoords, const std::vector<double> yCoords, const std::vector<double> zCoords){
  std::vector<double> point(3);
  static vectorList gridPoints;
  gridPoints.clear();
    
  for(auto x: xCoords){
    for(auto y: yCoords){
      for(auto z: zCoords){
	point = {x, y, z};
	gridPoints.push_back(point);
      }
    }
  }
  return &gridPoints;
}


// vectorList* Grid::meshGrid(const std::vector<double> *xCoords, const std::vector<double> *yCoords){
//   std::vector<double> point(3);
//   static vectorList gridPoints;
  
//   for(auto x: *xCoords){
//     for(auto y: *yCoords){
//       point = std::vector<double>({x, y});
//       gridPoints.push_back(point);
//     }
//   }
//   return &gridPoints;
// }

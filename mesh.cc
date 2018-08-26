// mesh.cc --- 
// 
// Filename: mesh.cc
// Description: 
// 
// Author:    Yu Lu
// Email:     yulu@utexas.edu
// Github:    https://github.com/SuperYuLu 
// 
// Created: Mon Aug 13 22:53:04 2018 (-0500)
// Version: 
// Last-Updated: Sun Aug 26 13:03:19 2018 (-0500)
//           By: yulu
//     Update #: 161



#include "mesh.h"

Mesh :: Mesh(void){
  meshgrid = {};
  x = {};
  y = {};
  z = {};
}



void Mesh :: genMesh(double x1, double y1, double z1,
		     double x2, double y2, double z2, double resolution){
  std::cout << "Generating meshgrid points..." << std::endl;
  double temp;

  // make sure grid are always from low to heigh along each axis
  if(x1 > x2){
    temp = x1;
    x1 = x2;
    x2 = temp;}

  if(y1 > y2){
    temp = y1;
    y1 = y2;
    y2 = temp;}
    
  if(z1 > z2){
    temp = z1;
    z1 = z2;
    z2 = temp;}

  // generate grid for each axis 
  x = gen1DGrid(x1, x2, resolution);
  y = gen1DGrid(y1, y2, resolution);
  z = gen1DGrid(z1, z2, resolution);

  // generate meshgrid
  meshgrid = *meshGrid(x, y, z);
  std::cout << "Totoal meshgrid points generated: " << meshgrid.size() << std::endl;
}


void Mesh :: genMesh(double x1, double y1, double z1){
  std::cout << "Generating meshgrid points..." << std::endl;
  x = std::vector<double>({x1});
  y = std::vector<double>({y1});
  z = std::vector<double>({z1});
  meshgrid = *meshGrid(x, y, z);
  std::cout << "Totoal meshgrid points generated: " << meshgrid.size() << std::endl;
}


void Mesh :: save(void){
  std::ofstream f("meshgrid.dat", std::ios::out);
  if(f.is_open()){
    f << "#" << "x\t" << "y\t" << "z" << std::endl; //gnuplot comment
    writeVectorList(f, meshgrid);
    f.close();
    std::cout << "Mesh data saved in file: " << "meshgrid.dat" << std::endl;
  }
}


std::vector<double> Mesh::gen1DGrid(double xBegin, double xEnd, double xResolution){
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


vectorList* Mesh::meshGrid(const std::vector<double> xCoords, const std::vector<double> yCoords, const std::vector<double> zCoords){
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

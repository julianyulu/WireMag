// wire.cc --- 
// 
// Filename: wire.cc
// Description: 
// 
// Author:    Yu Lu
// Email:     yulu@utexas.edu
// Github:    https://github.com/SuperYuLu 
// 
// Created: Sun Jul 22 13:12:30 2018 (-0500)
// Version: 
// Last-Updated: Tue Aug 14 10:43:15 2018 (-0500)
//           By: yulu
//     Update #: 604
// 

#include <algorithm>
#include <cmath>
#include "wire.h"
#include "vectorAddOns.h"


const vectorList default_path = {{0.618, 0.618, 0.618}};


Wire :: Wire(const vectorList &path_value = default_path,  double unit_length_value = 0.1, double current_value = 1.0){
  current = current_value;
  path = path_value;
  unit_length = unit_length_value;
}

vectorList Wire :: pathDiscretize(void) const{
  vectorList  dpath = path;
  std::vector<double> elemVector;
  std::vector<double> insertVector;
  vectorList::iterator iterElemEnd;
  double elemNorm;
  double npts;

  if(dpath.size() < 2){
    std::cerr << "There must be at least two point in the path !" << std::endl;}

  iterElemEnd = ++dpath.begin();
  elemVector.resize(dpath.front().size());
  insertVector.resize(dpath.front().size());

  while(iterElemEnd != dpath.end()) {
    
    // original element list and norm lengh 
    elemVector = *iterElemEnd - *std::prev(iterElemEnd); 
    elemNorm = l2_norm(elemVector);        

    // new element and norm for discretized units
    npts = std::floor(elemNorm / unit_length) - 1; // num points to insert
    elemVector = elemVector / elemNorm ;   
    elemNorm = elemNorm / (npts + 1);
    for(int i = 1; i <=  npts; i++) {

      // Discretize method 1: stick to specified unit_length
      // insertVector = *std::prev(iterElemEnd) + elemVector * unit_length;

      // Discretize method 2: stick to the number of sections and evenly discretize
      insertVector = *std::prev(iterElemEnd) + elemVector * elemNorm;
      dpath.insert(iterElemEnd, insertVector);
    }
    iterElemEnd++;
  }
  return dpath;
}
         


IdL_R Wire :: elementIdLR(void) const{
  vectorList dpath = pathDiscretize();
  static IdL_R elemIdLR;
  if(dpath.size() < 2){
    std::cerr << "There must be at least two point in the discretized path !" << std::endl;
  } else{
    for (vectorList::iterator iter = dpath.begin(); iter != std::prev(dpath.end()); iter ++){
      elemIdLR.IdL.push_back((*std::next(iter) - *iter) * current);
      elemIdLR.R.push_back((*std::next(iter) + *iter) * 0.5);
    }
  }

  return elemIdLR;
}

  
void Wire :: pathExtend(const vectorList &extPath){
  vectorList tempExtPath = extPath;
  if(path == default_path){
    path = tempExtPath;
  }else if(tempExtPath.front() == path.back()){
    tempExtPath.pop_front();
    path.splice(path.end(), tempExtPath);
  }else{
    path.splice(path.end(), tempExtPath);
  }
}

void Wire :: pathExtend(const std::vector<double> &extPath){
  if(path == default_path){
    path = vectorList {extPath};
  }else if(path.back() != extPath){
    path.push_back(extPath);
  }
}

void Wire :: pathTranslate(const std::vector<double> &xyz){
  std::transform(path.begin(), path.end(), path.begin(),
		 [xyz](std::vector<double> x){ return (x + xyz);});
}


void Wire :: pathTranslate(double x, double y, double z){
  std::vector<double> xyz = {x, y, z};
  std::transform(path.begin(), path.end(), path.begin(),
		 [xyz](std::vector<double> x){ return (x + xyz);});
}

void Wire :: pathRotate(const std::vector<double> &axis, double deg = 0){
  double radians = deg * 3.1415926 / 180.0 ;
  double cos = std::cos(radians);
  double sin = std::sin(radians);
  std::vector< std:: vector< double>> rotateVector(3);

  rotateVector[0] = {axis[0] * axis[0] * (1 - cos) + cos,
		   axis[0] * axis[1] * (1 - cos) - axis[2] * sin,
		   axis[0] * axis[2] * (1 - cos) + axis[1] * sin};
  rotateVector[1] = {axis[1] * axis[0] * (1 - cos) + axis[2] * sin,
		     axis[1] * axis[1] * (1 - cos) + cos,
		     axis[1] * axis[2] * (1 - cos) - axis[0] * sin};
  rotateVector[2] = {axis[2] * axis[0] * (1 - cos) - axis[1] * sin,
		     axis[2] * axis[1] * (1 - cos) + axis[0] * sin,
		     axis[2] * axis[2] * (1 - cos) + cos};
  
  std::transform(path.begin(), path.end(), path.begin(),
		 [rotateVector](std::vector<double> x){
		   return std::vector<double> {
		     vector_dot(x, rotateVector[0]),
		       vector_dot(x, rotateVector[1]),
		       vector_dot(x, rotateVector[2])};});
}


vectorList Wire :: linearPath(const std::vector<double> &pt1 = {0, 0, 0},
		    const std::vector<double> &pt2 = {0, 0, 1}){
  return (vectorList {pt1, pt2});
}



vectorList Wire :: rectangularPath(double dx, double dy){
  double dx2 = dx / 2;
  double dy2 = dy / 2;
  vectorList rectPath = {{-dx2, dy2, 0},
		       {dx2, dy2, 0},
		       {dx2, -dy2, 0},
		       {-dx2, -dy2, 0},
		       {-dx2, dy2, 0}};
  return rectPath;
}
		      
  
vectorList Wire :: ellipticalPath(double rx = 1, double ry = 0.5, int pts = 50){
  vectorList elliPath;
  double pi = 3.1415826;
  for(int p = 0; p <= pts; p++){
    double radians = p * 2 * pi / pts;
    elliPath.push_back(std::vector<double> {std::sin(radians) * rx,
					    std::cos(radians) * ry,
					      0.0});
  }
  return elliPath;
}


vectorList Wire ::circularPath(double radius = 0.5, int pts = 50){
  return ellipticalPath(radius, radius, pts);
}


vectorList Wire :: ellipticalSolenoidPath(double rx = 0.5, double ry = 0.2,
				double pitch = 0.01, int layers = 1,
				int turns_per_layer = 10, int points_per_turn = 40){
  double const PI = 3.1415926;
  vectorList esPath;
  double radians = 0;  
    
  for(int i = 0; i < layers; i++){
    rx = rx + i * pitch / 2;
    ry = ry + i * pitch / 2;
    for(int j = 0; j < turns_per_layer; j++){
      for(int k = 0; k < points_per_turn; k++){
	radians = k * 2 * PI / points_per_turn + j * 2 * PI;
	esPath.push_back(std::vector<double> {rx * std::cos(radians),
						  ry * std::sin(radians),
						  radians / (2 * PI) * pitch});
      }
    }
  }
  return esPath;
}

vectorList Wire ::solenoidPath(double radius = 0.5, double pitch = 0.01,
		      int layers = 1, int turns_per_layer = 10,
		      int points_per_turn = 40){
  return ellipticalSolenoidPath(radius, radius, pitch, layers, turns_per_layer, points_per_turn);
}  
  
  
    
  

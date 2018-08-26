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
// Last-Updated: Sun Aug 26 13:02:05 2018 (-0500)
//           By: yulu
//     Update #: 681
// 


#include "wire.h"

Wire :: Wire(void){
  path = vectorList({});
  unit_length = 0.0;
  discretized = false;
}


Wire :: Wire(const vectorList &path_value,  double unit_length_value){
  path = path_value;
  unit_length = unit_length_value;
  discretized = false;
}

void Wire :: save(void){
  std::ofstream f("wire.dat", std::ios::out);
  if(f.is_open()){
    f << "#" << "x\t" << "y\t" << "z" << std::endl; //gnuplot comment 
    writeVectorList(f, path);
    f.close();
    std::cout << "Wire geometry data saved in file: " << "wire.dat" << std::endl;
  }
}


void Wire :: pathDiscretize(void){
  std::vector<double> elemVector;
  std::vector<double> insertVector;
  vectorList::iterator iterElemEnd;
  double elemNorm;
  double npts;

  if(path.size() < 2){
    std::cerr << "There must be at least two points in the path !" << std::endl;
    return;
  }

  if(unit_length <= 0){
    std::cerr << "Unit length cannot be smaller than 0 ! Set correct value first" << std::endl;
    return;
  }

  iterElemEnd = ++path.begin();
  elemVector.resize(path.front().size());
  insertVector.resize(path.front().size());

  while(iterElemEnd != path.end()) {
    
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
      path.insert(iterElemEnd, insertVector);
    }
    iterElemEnd++;
  }
  discretized = true;
}
         




void Wire :: pathExtend(const vectorList &extPath){
  vectorList tempExtPath = extPath;
  if(path.empty()){
    path = tempExtPath;
  }else if(tempExtPath.front() == path.back()){
    tempExtPath.pop_front();
    path.splice(path.end(), tempExtPath);
  }else{
    path.splice(path.end(), tempExtPath);
  }
}

void Wire :: pathExtend(const std::vector<double> &extPath){
  if(path.empty()){
    path = vectorList {extPath};
  }else if(path.back() != extPath){
    path.push_back(extPath);
  }
}

void Wire :: pathTranslate(const std::vector<double> &xyz){
  if(path.empty()){
    std::cout<< "pathTranslate not applicable: path empty !" << std::endl;

  }else{
    std::transform(path.begin(), path.end(), path.begin(),
		   [xyz](std::vector<double> x){ return (x + xyz);});
  }   
}


void Wire :: pathTranslate(double x, double y, double z){
  std::vector<double> xyz = {x, y, z};
  if(path.empty()){
    std::cout<< "pathTranslate not applicable: path empty !" << std::endl;

  }else{
    std::transform(path.begin(), path.end(), path.begin(),
		   [xyz](std::vector<double> x){ return (x + xyz);});
  }
}

void Wire :: pathRotate(const std::vector<double> &axis, double deg = 0){
  double radians = deg * 3.1415926 / 180.0 ;
  double cos = std::cos(radians);
  double sin = std::sin(radians);
  if(path.empty()){
    std::cout<< "pathRotate not applicable: path empty !" << std::endl;

  }else{
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
}

 
vectorList* Wire :: linearPath(const std::vector<double> &pt1, const std::vector<double> &pt2){
  static vectorList linPath = {pt1, pt2};
  return &linPath;
}



vectorList* Wire :: rectangularPath(double dx, double dy){
  double dx2 = dx / 2;
  double dy2 = dy / 2;
  static vectorList rectPath = {{-dx2, dy2, 0},
		       {dx2, dy2, 0},
		       {dx2, -dy2, 0},
		       {-dx2, -dy2, 0},
		       {-dx2, dy2, 0}};
  return &rectPath;
}
		      
  
vectorList* Wire :: ellipticalPath(double rx, double ry, int pts){
  static vectorList elliPath;
  double pi = 3.1415826;
  for(int p = 0; p <= pts; p++){
    double radians = p * 2 * pi / pts;
    elliPath.push_back(std::vector<double> {std::sin(radians) * rx,
					    std::cos(radians) * ry,
					      0.0});
  }
  return &elliPath;
}


vectorList* Wire ::circularPath(double radius, int pts){
  return ellipticalPath(radius, radius, pts);
}


vectorList* Wire :: ellipticalSolenoidPath(double rx, double ry, double pitch, int layers,
					   int turns_per_layer,  int points_per_turn){
  double const PI = 3.1415926;
  static vectorList esPath;
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
  return &esPath;
}

vectorList* Wire ::solenoidPath(double radius, double pitch, int layers,
				int turns_per_layer, int points_per_turn){
  return ellipticalSolenoidPath(radius, radius, pitch, layers, turns_per_layer, points_per_turn);
}  

/*
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
  
*/  

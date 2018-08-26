/* mesh.h --- 
 * 
 * Filename: mesh.h
 * Description: 
 * 
 * Author:    Yu Lu
 * Email:     yulu@utexas.edu
 * Github:    https://github.com/SuperYuLu 
 * 
 * Created: Mon Aug 13 22:53:16 2018 (-0500)
 * Version: 
 * Last-Updated: Sun Aug 26 13:05:55 2018 (-0500)
 *           By: yulu
 *     Update #: 83
 * 
 */

#ifndef _mesh_h_
#define _mesh_h_

#include <list>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cmath>
#include "vectorOperation.h"

class Mesh{

public:
  vectorList meshgrid;
  std::vector<double> x;
  std::vector<double> y;
  std::vector<double> z;

  Mesh(void);
  void genMesh(double x1 = -1, double y1 = -1, double z1 = -1, // start corner 
	       double x2 =  1, double y2 =  1, double z2 =  1, // end corner
	       double resolution = 0.1); // resolution
  void genMesh(double x1, double y1, double z1); // overload for single point grid
  void save(void);
  
private:
  std::vector<double> gen1DGrid(double begin, double end, double resolution);
   vectorList* meshGrid(const std::vector<double> xCoords, const std::vector<double> yCoords, const std::vector<double> zCoords);
};


#endif //_mesh_h_

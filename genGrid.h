/* genGrid.h --- 
 * 
 * Filename: genGrid.h
 * Description: 
 * 
 * Author:    Yu Lu
 * Email:     yulu@utexas.edu
 * Github:    https://github.com/SuperYuLu 
 * 
 * Created: Mon Aug 13 22:53:16 2018 (-0500)
 * Version: 
 * Last-Updated: Thu Aug 23 10:16:21 2018 (-0500)
 *           By: yulu
 *     Update #: 60
 * 
 */

#ifndef _genGrid_h_
#define _genGrid_h_

#include <vector>
#include <list>
#include "vectorAddOns.h"
#include <fstream>
#include <string>

class Grid{

public:
  vectorList grid;

  Grid(void);
  //Grid(std::string kind = "cuboidVolumn");
  void save(void);
  vectorList* singlePiont(double x = 0.0,
			  double y = 0.0,
			  double z = 0.0);

  vectorList* line(double x1 = 0.0,
		   double y1 = 0.0,
		   double z1 = -1.0,
		   double x2 = 0.0,
		   double y2 = 0.0,
		   double z2 = 1.0,
		   double resolution = 0.1);

  vectorList* rectanglePlane(double x1 = -1.0,
			      double y1 = -1.0,
			      double z1 = 0.0,
			      double x2 = 1.0,
			      double y2 = 1.0,
			      double z2 = 0.0,
			      double resolution = 0.1);
  

  vectorList* cuboidVolumn(double x1 = -1.0,
			   double y1 = -1.0,
			   double z1 = -1.0,
			   double x2 = 1.0,
			   double y2 = 1.0,
			   double z2 = 1.0,
			   double resolution = 0.1);

  //vectorList* reduceDim(vectorList& input, int axis = 0, double value = 0);
private:
  std::vector<double> gen1DGrid(double begin, double end, double resolution);
 
  vectorList* meshGrid(const std::vector<double> xCoords, const std::vector<double> yCoords, const std::vector<double> zCoords);
  
  
};


#endif //_genGrid_h_

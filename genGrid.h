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
 * Last-Updated: Tue Aug 14 00:18:32 2018 (-0500)
 *           By: yulu
 *     Update #: 25
 * 
 */

#ifndef _genGrid_h_
#define _genGrid_h_

#include <vector>
#include <list>
#include "vectorAddOns.h"

typedef std::list< std::vector<double>> vectorList;

class Grid{

 public:
  vectorList* cuboidVolumn(double x1, double x2, double y1, double y2, double z1, double z2, double resolution);
  std::list<double>* gen1DGrid(double begin, double end, double resolution);
  vectorList* meshGrid(const std::list<double> *xCoords, const std::list<double> *yCoords, const std::list<double> *zCoords);
  
};


#endif //_genGrid_h_

/* wire.h --- 
 * 
 * Filename: wire.h
 * Description: 
 * 
 * Author:    Yu Lu
 * Email:     yulu@utexas.edu
 * Github:    https://github.com/SuperYuLu 
 * 
 * Created: Wed Aug  8 23:49:50 2018 (-0500)
 * Version: 
 * Last-Updated: Mon Aug 20 16:55:34 2018 (-0500)
 *           By: yulu
 *     Update #: 129
 * 
 */

#ifndef _wire_h_
#define _wire_h_

#include <list>
#include <vector>
#include "vectorAddOns.h"



class Wire{

public:
  double unit_length;
  vectorList path;
  bool discretized;
  Wire(void);
  Wire(const vectorList &, double);
  
  
  //vectorList pathDiscretize(void) const;
  void pathDiscretize(void);
  
  void pathExtend(const vectorList &extPath);
  void pathExtend(const std::vector<double> &extPath);
  void pathTranslate(const std::vector<double> &xyz);
  void pathTranslate(double x, double y, double z);
  void pathRotate(const std::vector<double> &axis, double deg);

  vectorList* linearPath(const std::vector<double> &pt1 = std::vector<double>({-1.0, 0, 0}),
			const std::vector<double> &pt2 = std::vector<double>({1.0, 0, 0}));
  
  vectorList* rectangularPath(double dx = 1.0,
			      double dy = 1.0);
  
  vectorList* ellipticalPath(double rx = 1,
			     double ry = 0.5,
			     int pts = 50);
  
  vectorList* circularPath(double radius = 0.5,
			   int pts = 50);
  
  vectorList* ellipticalSolenoidPath(double rx = 1.0,
				     double ry = 0.5,
				     double pitch = 0.1,
				     int layers = 1,
				     int turns_per_layer = 2,
				     int points_per_turn = 40);


  vectorList* solenoidPath(double radius = 0.5,
			   double pitch = 0.1,
			   int layers = 1,
			   int turns_per_layer = 10,
			   int points_per_turn = 40);
    
  
  //IdL_R elementIdLR (void) const;
  
};

#endif //_wire_h_

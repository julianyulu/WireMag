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
 * Last-Updated: Tue Aug 14 00:18:40 2018 (-0500)
 *           By: yulu
 *     Update #: 88
 * 
 */

#ifndef _wire_h_
#define _wire_h_

#include <list>
#include <vector>

typedef std::list< std::vector <double>> vectorList;

struct IdL_R{
  vectorList IdL;
  vectorList R;
};
  


class Wire{

public:
  double current;
  double unit_length;
  vectorList path;
  
  Wire(const vectorList &, double,  double);
  
  IdL_R elementIdLR (void) const;
  vectorList pathDiscretize(void) const;
  void pathExtend(const vectorList &extPath);
  void pathExtend(const std::vector<double> &extPath);
  void pathTranslate(const std::vector<double> &xyz);
  void pathTranslate(double x, double y, double z);
  void pathRotate(const std::vector<double> &axis, double deg);

  vectorList LinearPath(const std::vector<double> &pt1, const std::vector<double> &pt2);
  vectorList rectangularPath(double dx, double dy);
  vectorList ellipticalPath(double rx, double ry, int pts);
  vectorList circularPath(double radius, int pts);
  
  vectorList ellipticalSolenoidPath(double rx,  double ry, double pitch, int layers,
				  int turns_per_layer, int points_per_turn);
  
  vectorList solenoidPath(double radius, double pitch, int layers, int turns_per_layer,
			int points_per_turn);
  
};


#endif //_wire_h_

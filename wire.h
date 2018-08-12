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
 * Last-Updated: Sun Aug 12 14:06:01 2018 (-0500)
 *           By: yulu
 *     Update #: 86
 * 
 */

#ifndef _wire_h_
#define _wire_h_

#include <list>
#include <vector>

typedef std::list< std::vector <double>> listVect;

struct IdL_R{
  listVect IdL;
  listVect R;
};
  


class Wire{

public:
  double current;
  double unit_length;
  listVect path;
  
  Wire(const listVect &, double,  double);
  
  IdL_R elementIdLR (void) const;
  listVect pathDiscretize(void) const;
  void pathExtend(const listVect &extPath);
  void pathExtend(const std::vector<double> &extPath);
  void pathTranslate(const std::vector<double> &xyz);
  void pathTranslate(double x, double y, double z);
  void pathRotate(const std::vector<double> &axis, double deg);

  listVect LinearPath(const std::vector<double> &pt1, const std::vector<double> &pt2);
  listVect rectangularPath(double dx, double dy);
  listVect ellipticalPath(double rx, double ry, int pts);
  listVect circularPath(double radius, int pts);
  
  listVect ellipticalSolenoidPath(double rx,  double ry, double pitch, int layers,
				  int turns_per_layer, int points_per_turn);
  
  listVect solenoidPath(double radius, double pitch, int layers, int turns_per_layer,
			int points_per_turn);
  
};


#endif //_wire_h_

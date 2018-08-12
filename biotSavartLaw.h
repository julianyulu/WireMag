/* biotSavartLaw.h --- 
 * 
 * Filename: biotSavartLaw.h
 * Description: 
 * 
 * Author:    Yu Lu
 * Email:     yulu@utexas.edu
 * Github:    https://github.com/SuperYuLu 
 * 
 * Created: Sat Aug 11 21:16:38 2018 (-0500)
 * Version: 
 * Last-Updated: Sun Aug 12 14:08:58 2018 (-0500)
 *           By: yulu
 *     Update #: 42
 * 
 */

#ifndef _biot_savart_law_h
#define _biot_savart_law_h
#include<vector>
#include<list>
#include "vectorAddOns.h"
#include "wire.h"

class BiotSavartLaw{
 public:
  std::list<const Wire*> wires;

  BiotSavartLaw(void);
  BiotSavartLaw(const Wire* wireObj);

  void addWires(const Wire* wireObj);
  void clear(void);
  listVect* calculateBField(const listVect &points) const;
private:
  std::vector<double> crossProduct(const std::vector<double> &x, const std::vector<double> &y) const;
  
  std::vector<double> singlePointBField(const std::vector<double> &r, const listVect &IdL,
  					const listVect &R) const;

  
};



  
  


#endif //_biot_savart_law_h

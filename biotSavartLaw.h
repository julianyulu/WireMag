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
 * Last-Updated: Sun Aug 12 00:18:04 2018 (-0500)
 *           By: yulu
 *     Update #: 17
 * 
 */

#ifndef _biot_savart_law_h
#define _biot_savart_law_h
#include<vector>
#include<list>
#include "wire.h"

class BiotSavartLaw{
 public:
  std::list<const listVect*> wires;

  BiotSavartLaw(void);
  BiotSavartLaw(const listVect* wireList);

  void addWires(const listVect* wireList);

  void clear(void);

  
  
  //std::vector<double> crossProduct(const std::vector<double> &x, const std::vector<double> &y);
};

  
  


#endif //_biot_savart_law_h

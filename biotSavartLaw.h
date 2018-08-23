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
 * Last-Updated: Thu Aug 23 09:54:11 2018 (-0500)
 *           By: yulu
 *     Update #: 93
 * 
 */

#ifndef _biot_savart_law_h
#define _biot_savart_law_h
#include <vector>
#include <list>
#include "vectorAddOns.h"
#include "wire.h"
#include "genGrid.h"

class BiotSavartLaw{
public:
  std::list<const Wire*> wires;
  const Grid* mesh;
  double current;
  vectorList* magField;
  
  BiotSavartLaw(void);
  BiotSavartLaw(const Wire* ptrWireObj, const Grid* gridObj, double current_value);

  
  void addWires(const Wire* wireObj);
  void clearWires(void);

  std::vector<double> singlePointBField(const std::vector<double> &r);
  void meshGridBField(void);
  
  
private:
  const vectorList* ptr_IdL;
  const vectorList* ptr_R;
  
  const vectorList* IdL(void);
  const vectorList* R(void);
  std::vector<double> crossProduct(const std::vector<double> &x, const std::vector<double> &y);

};



  
  


#endif //_biot_savart_law_h

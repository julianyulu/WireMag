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
 * Last-Updated: Mon Aug 20 23:07:04 2018 (-0500)
 *           By: yulu
 *     Update #: 85
 * 
 */

#ifndef _biot_savart_law_h
#define _biot_savart_law_h
#include<vector>
#include<list>
#include "vectorAddOns.h"
#include "wire.h"
#include "genGrid.h"

class BiotSavartLaw{
 public:
  std::list<const Wire*> wires;
  const Grid* mesh;
  double current;
  
  BiotSavartLaw(void);
  BiotSavartLaw(const Wire* ptrWireObj, const Grid* gridObj, double current_value);

  
  void addWires(const Wire* wireObj);
  void clearWires(void);

  std::vector<double> singlePointBField(const std::vector<double> &r);
  vectorList* meshGridBField(void);
  
  
  
  
private:
  const vectorList* ptr_IdL;
  const vectorList* ptr_R;
  
  const vectorList* IdL(void);
  const vectorList* R(void);
  std::vector<double> crossProduct(const std::vector<double> &x, const std::vector<double> &y);
  
  

};



  
  


#endif //_biot_savart_law_h

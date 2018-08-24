/* field.h --- 
 * 
 * Filename: field.h
 * Description: 
 * 
 * Author:    Yu Lu
 * Email:     yulu@utexas.edu
 * Github:    https://github.com/SuperYuLu 
 * 
 * Created: Thu Aug 23 09:55:30 2018 (-0500)
 * Version: 
 * Last-Updated: Fri Aug 24 00:13:35 2018 (-0500)
 *           By: yulu
 *     Update #: 23
 * 
 */

#ifndef _field_h_
#define _field_h_

#include "vectorAddOns.h"
#include "grid.h"
#include "wire.h"
#include "bioSavartLaw.h"
#include <list>
classs Field{
 public:
  const vectorList* grid;
  const vectorList* field;
  const vectorList sliced;
  
  Field(void);
  Field(const vectorList* ptrGrid, const vectorList* ptrFeild);

  void sliceX(double x);

  void save(void);
  
 private:
  std::list<double>* normField(const vectorList* inputField);
  const vectorList* findSingleXYZ(char axis, double value);

};




#endif // _field_h_

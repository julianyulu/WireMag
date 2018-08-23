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
 * Last-Updated: Thu Aug 23 10:25:28 2018 (-0500)
 *           By: yulu
 *     Update #: 18
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
  
  Field(void);
  Field(vectorList* ptrGrid, vectorList* ptrFeild);

  void save(void);
 private:
  std::list<double>* normField(const vectorList* inputField);
  

};




#endif // _field_h_

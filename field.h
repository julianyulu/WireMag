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
 * Last-Updated: Sat Aug 25 12:41:07 2018 (-0500)
 *           By: yulu
 *     Update #: 38
 * 
 */

#ifndef _field_h_
#define _field_h_

#include "vectorAddOns.h"
#include "genGrid.h"
#include "wire.h"
#include "biotSavartLaw.h"
#include <list>

class Field{
 public:
  const vectorList* grid;
  const vectorList* field;
  vectorList sliced;
  
  Field(void);
  Field(const vectorList* ptrGrid, const vectorList* ptrFeild);

  void sliceX(double x);
  void sliceY(double y);
  void sliceZ(double z);

  void scalarField();
  void save(void);
  
 private:
  bool normalize = false;
  vectorList* normField(const vectorList* inputField);
  const vectorList* findSingleXYZ(char axis, double value);

};




#endif // _field_h_

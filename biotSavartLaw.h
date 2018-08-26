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
 * Last-Updated: Sun Aug 26 13:52:25 2018 (-0500)
 *           By: yulu
 *     Update #: 143
 * 
 */

#ifndef _Biot_Savart_Law_H_
#define _Biot_Savart_Law_H_

#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <algorithm>
#include "vectorOperation.h"
#include "wire.h"
#include "mesh.h"

class BiotSavartLaw{
public:
  double current;
  vectorList magField;
  const Mesh* mesh;
  std::list<const Wire*> wires;
    
  BiotSavartLaw(void);
  BiotSavartLaw(const Wire* ptrWireObj, const Mesh* meshObj, double current_value);

  
  void addWires(const Wire* wireObj);
  void clearWires(void);
  void calculate(void);
  
  double fieldAt(double x, double y, double z);
  void startAnalysis(void);
  void normField(void);
  void sliceMeshX(double x);
  void sliceMeshY(double y);
  void sliceMeshZ(double z);
  void saveAsCSV(void);
    
private:
  const vectorList* ptr_IdL;
  const vectorList* ptr_R;
  vectorList selectedField;
  vectorList selectedMesh;
    
  const vectorList* IdL(void);
  const vectorList* R(void);

  std::vector<double> singlePointField(const std::vector<double> &r);
  
  void filterAxisField(vectorList& grid, vectorList& field, char axis, double value);
  std::list<double> uniqueGrid(char axis, const vectorList& grid);
};



  
  


#endif //_Biot_Savart_Law_H_

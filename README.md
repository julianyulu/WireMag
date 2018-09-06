# WireMag  
WireMag is a C++ library for calculating the magnetic field in 3D space generated current in arbitrary wire shape.   

## Compile  
This library uses CMake for compliation, by default using g++ (C11). To compile, make a new folder in the package directory:  
```bash
mkdir build
cd build
```
Then call CMake to compile:  
```bash
cmake ..
```
An executable 'run' will be generated.  


## How it Works  
To calculate the magnetic field at certain grid with certain wire shape, one has to create to first creat two object:  
1. Object of class Wire: the shape of wire and it's discritize resolution.  
   There are also supplements class method to help creat common wire shapes with flexiable configuration parameters   
```C
Wire w1;
w1.path = *w1.solenoidPath(5.1e-3, 0.405e-3, 4, 2, 20);
w1.pathTranslate(0, 0, -2.5e-3);
w1.unit_length = 2e-3;
w1.pathDiscretize();
```

2. Object of class Mesh: the mesh grid where the magnetic field will be calculated.  
   The mesh grid creator can be used to create rectangular meshgrid:  
```C
Mesh m;
m.genMesh(0, -5e-3,  -5e-3, 0, 5e-3,  5e-3, 0.1e-3);
m.save();
```
   
3. Calculate  magnetic field based on [Biot Savart Law](https://en.wikipedia.org/wiki/Biot%E2%80%93Savart_law). To do this pass the wire object and mesh object to class BiotSavartLaw initializer:  
```C
BiotSavartLaw bst;
bst.addWires(&w1);
bst.addWires(&w2);
bst.mesh = &m;
bst.current = 500;
bst.calculate();
bst.saveWires();
```

4. After field data has been calculated, one can optionally choose to do post analysis, e.g. calculate the norm of the field or choose a slice for evaluation:  
```C
bst.startAnalysis();
//bst.sliceMeshX(0);
bst.normField();
bst.saveAsCSV();
```

## Examples
Example of generated wire geometry:  
[wire-example](https://raw.githubusercontent.com/SuperYuLu/WireMag/master/img/wire_example.png)  

Example of generated slice meshgrid:  
[mesh-example](https://raw.githubusercontent.com/SuperYuLu/WireMag/master/img/mesh_example.png)  

Result of calculated field:  
[field-example](https://github.com/SuperYuLu/WireMag/blob/master/img/field_example.png)  

## Status  
Under development   

## TODO  
+ Make GUI window for user-firendly access 
+ Add plotting module using python 
+ Add unittest 



#ifndef arrayoftriangle_h
#define arrayoftriangle_h

#include <stdio.h>
#include "point.h"
#include "triangle.h"

typedef struct tagArrayOfTriangles {
  Triangle **storage;
  int preservedCount;
  int count;
} ArrayOfTriangles;

ArrayOfTriangles *createArrayOfPoints(int aReserved);
void destroyArrayOfPoints(ArrayOfTriangles *anArray);

void addTriangle(ArrayOfTriangles *anArray, Triangle *aTriangle);
Point *getTriangleAt(ArrayOfTriangles *anArray, int aIndex);

void printArrayOfTriangles(ArrayOfTriangles *anArray);
int countArrayOfTriangles(ArrayOfTriangles *anArray);

//void addPointAtIndex(ArrayOfPoints *anArray, Point *aPoint, int anIndex);
//Point *remotePointAtIndex(ArrayOfPoints *anArray, int anIndex);


#endif

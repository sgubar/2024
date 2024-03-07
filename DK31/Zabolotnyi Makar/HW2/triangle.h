#ifndef triangle_h
#define triangle_h

#include <stdio.h>
#include "point.h"
#include "points.h"


typedef struct tagTriangle {
  ArrayOfPoints *points;
} Triangle;

Triangle *createTriangle(int ax, int ay, int bx, int by, int cx, int cy);
Triangle *createTriangleByPoints(Point *anA, Point *aB, Point *aC);
Triangle *createEmptyTriangle(void);

void destroyTriangle(Triangle *aTriangle);

void printTriangle(Triangle *aTriangle);
double areaTriangle(Triangle *aTriangle);

#endif 

#ifndef triangle_h
#define triangle_h

#include <stdio.h>
#include "point.h"

typedef struct tagTriangle{
  Point *A;
  Point *B;
  Point *C;
} Triangle;

Triangle *createTriangle(int ax, int ay, int bx, int by, int cx, int cy);
Triangle *createTriangleByPoints(Point *A, Point *B, Point *C);

void destroyTriangle(Triangle *aTriangle);
void printTriangle(Triangle *aTriangle);
double areaOfTriangle(Triangle *aTriangle);

#endif

#include "triangle.h"
#include <stdlib.h>
#include <math.h>

double side(Point *A, Point *B);

Triangle *createTriangle(int ax, int ay, int bx, int by, int cx, int cy){
  Triangle *result = (Triangle *)malloc(sizeof(Triangle));
  if (NULL != result){
    result->A = createPoint(ax, ay);
    result->B = createPoint(bx, by);
    result->C = createPoint(cx, cy);
  }
  return result;
}

Triangle *createTriangleByPoints(Point *A, Point *B, Point *C){
  if (NULL == A || NULL == B || NULL == C){
    return NULL;
  }
  return createTriangle(A->x, A->y, B->x, B->y, C->x, C->y);
  
}

void destroyTriangle(Triangle *aTriangle){
  if (NULL == aTriangle){
    return;
  }
  destroyPoint(aTriangle->A);
  destroyPoint(aTriangle->B);
  destroyPoint(aTriangle->C);
  free(aTriangle);
}

void printTriangle(Triangle *aTriangle){
  if (NULL == aTriangle){
    return;
  }
  printPoint(aTriangle->A);
  printf(" - ");
  printPoint(aTriangle->B);
  printf(" - ");
  printPoint(aTriangle->C);
}

double areaOfTriangle(Triangle *aTriangle){
  if (NULL == aTriangle){
    return-1;
  }
  double area = 0;
  
  Point *a = aTriangle->A;
    Point *b = aTriangle->B;
    Point *c = aTriangle->C;
    double ab = side(a, b);
    double ac = side(a, c);
    double bc = side(b, c);
    double p = (ab + ac + bc) / 2;
    area = sqrt(p * (p - ab) * (p - ac) * (p - bc));

  return area;
}

double side(Point *A, Point *B) {
  if (NULL == A || NULL == B) {
    return 0;
  }

  return sqrt((B->x - A->x) * (B->x - A->x) + (B->y - A->y)*(B->y - A->y));
}

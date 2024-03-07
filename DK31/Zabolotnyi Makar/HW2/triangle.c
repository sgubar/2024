#include "triangle.h"
#include <stdlib.h>
#include <math.h>

double side(Point *A, Point *B);

Triangle *createEmptyTriangle(void) {
  Triangle *result = (Triangle *)malloc(sizeof(Triangle));

  if (NULL != result) {
    result->points = createArrayOfPoints(3);
    if (NULL == result->points) { //failed to create internal storage
      free(result);
      return NULL;
    }
  }

  return result;
}

Triangle *createTriangle(int ax, int ay, int bx, int by, int cx, int cy) {
  Triangle *result = createEmptyTriangle();

  if (NULL != result) {
    addPoint(result->points, createPoint(ax, ay));
    addPoint(result->points, createPoint(bx, by));
    addPoint(result->points, createPoint(cx, cy));
  }

  return result;
}

Triangle *createTriangleByPoints(Point *anA, Point *aB, Point *aC) {
  if (NULL == anA || NULL == aB || NULL == aC) {
    return NULL;
  }

  return createTriangle(anA->x, anA->y, aB->x, aB->y, aC->x, aC->y);
}



void destroyTriangle(Triangle *aLine) {
  if (NULL == aLine) {
    return ;
  }

  // destroy all owned points which are present in our storage
  for (int i = 0; i < countArrayOfPoints(aLine->points); i++) {
    destroyPoint(getPointAt(aLine->points, i));
  }
}

void printTriangle(Triangle *aLine) {
  if (NULL == aLine) {
    return ;
  }

  // destroy all owned points which are present in our storage
  for (int i = 0; i < countArrayOfPoints(aLine->points); i++) {
    printPoint(getPointAt(aLine->points, i));
    printf("-");
  }
}

double areaTriangle(Triangle *aLine) {
  if (NULL == aLine) {
    return 0;
  }

  int count = countArrayOfPoints(aLine->points);

  if (count <= 1) {
    return 0;
  }

  Point *first = getPointAt(aLine->points, 0);
  double area = 0;

    Point *a = getPointAt(aLine->points, 0);
    Point *b = getPointAt(aLine->points, 1);
    Point *c = getPointAt(aLine->points, 2);
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

#include <stdio.h>
#include "point.h"
#include "triangle.h"
#include "ArrayOfTriangle.h"

int main(int argc, const char * argv[]) {

  // insert code here...
  printf("Hello, World!\n");

  Point *a = enterPoint();
  Point *b = enterPoint();
  Point *c = enterPoint();

  Triangle *triangle = createTriangleByPoints(a, b, c);
  printTriangle(triangle);
  printf("\n");
  Triangle *triangle2 = createTriangle(1, 1, 1, 5, 4, 1);
  ArrayOfTriangles *array = createArrayOfTriangles(2);
  addTriangle(array, triangle);
  addTriangle(array, triangle2);
  printArrayOfTriangles(array);
  printf("\n");
  printTriangle(getTriangleAt(array, 0));

  destroyPoint(a);
  destroyPoint(b);
  destroyPoint(c);
  destroyTriangle(triangle); 
  destroyTriangle(triangle2);
  destroyArrayOfTriangles(array);

  return 0;

}

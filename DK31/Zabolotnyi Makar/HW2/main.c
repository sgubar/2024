#include <stdio.h>
#include "point.h"
#include "triangle.h"


int main(int argc, const char * argv[]) {

  // insert code here...
  printf("Hello, World!\n");

  Point *a = enterPoint();
  Point *b = enterPoint();
  Point *c = enterPoint();

  Triangle *triangle = createTriangleByPoints(a, b, c);
  printTriangle(triangle);
  printf("\n");
  printf("Area: %f\n", areaOfTriangle(triangle));

  destroyPoint(a);
  destroyPoint(b);
  destroyPoint(c);
  destroyTriangle(triangle);  

  return 0;

}

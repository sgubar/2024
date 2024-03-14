#include <stdio.h>
#include "point.h"
#include "rect.h"
#define MOD(n) (n < 0 ? -n : n)

int main(void){
  
  printf("Hello, World!\n");
  
  Point *A = createPoint(5, 6);
  printPoint(A);
  printf("\n");

  Point *C = {3, 6};
  printPoint(&C);
  printf("\n");
  
  Rectangle *R = create_Rectangle(A, C);
  double area = calculateRectangleArea(R);
  
  destroyPoint(A);
  destroyPoint(C);

return 0;
}

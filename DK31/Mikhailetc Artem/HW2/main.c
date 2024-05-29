#include <stdio.h>
#include "point.h"
#include "rect.h"
#define MOD(n) (n < 0 ? -n : n)

int main(void){

  printf("Hello, World!\n");

  Point *A = createPoint(3, 5); 
  printPoint(A);
  printf("\n");

  Point C = {2, 6}; 
  printPoint(&C);
  printf("\n");

  Rectangle *R = create_Rectangle(A, &C); 
  double area = calculateRectangleArea(R);
  printf("Площа прямокутника: %.2f\n", MOD(area)); 

  destroyPoint(A); 
return 0;
}

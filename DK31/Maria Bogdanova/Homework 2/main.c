#include <stdio.h>
#include "point.h"
#include "rect.h"
#define MOD(n) (n < 0 ? -n : n)

int main(void){

  printf("Hello, World!\n");

  Point *A = createPoint(3, 5); //точка А
  printPoint(A);
  printf("\n");

  Point C = {2, 6}; //точка С
  printPoint(&C);
  printf("\n");

  Rectangle *R = create_Rectangle(A, &C); //ствоюємо прямокутник 
  double area = calculateRectangleArea(R);//обчислюємо площу
  printf("Площа прямокутника: %.2f\n", MOD(area)); 

  destroyPoint(A); //видаляємо точку А
//ми не видаляємо точку C, оскільки ми передаємо на неї лише вказівник, а не сам об'єкт
return 0;
}

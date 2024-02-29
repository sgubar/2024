#include <stdio.h>
#include <stdlib.h>
#include "rec.h"

 #define MOD(n) (n < 0 ? -n : n)

int main() {
  
  struct Rec myRec;

    // Користувач вводить координати точок прямокутника
    printf("Введіть координати лівої верхньої точки (x y): ");
    scanf("%lf %lf", &myRec.topLeft.x, &myRec.topLeft.y);

    printf("Введіть координати правої нижньої точки (x y): ");
    scanf("%lf %lf", &myRec.bottomRight.x, &myRec.bottomRight.y);
  double area = calculateRectangleArea(myRec);

    printf("Площа прямокутника: %.2f\n", MOD(area));

    return 0;
}

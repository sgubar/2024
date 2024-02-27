#include "math.h"
#include <stdio.h>
int main() {
  printf("Hello, World!\n"); //Виведення повідомлення "Hello world!"
  int A;
  int B;
  int C;
  int D; //Задаємо вхідні дані
  printf("A: ");
  scanf("%d", &A);
  printf("B: ");
  scanf("%d", &B);
  printf("C: ");
  scanf("%d", &C);
  printf("D: ");
  scanf("%d", &D);
  printf("2^D: %f\n", power(2, D));
  printf("C^3: %f\n", power(C, 3)); //Використовуємо степеневу функцію
  printf("The result of calculation Q: %d\n", q(A, B, C, D)); //Вивід результату на екран

  return 1;
}

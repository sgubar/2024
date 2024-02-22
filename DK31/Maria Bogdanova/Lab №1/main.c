#include "math.h"
#include <stdio.h>
int main() {
  printf("Hello, World!\n"); //Виведення повідомлення "Hello world!"
  int A; int B; int C; int D; //Задаємо дані для входу 
  printf("A: ");
  scanf("%d", &A);
  printf("B: ");
  scanf("%d", &B);
  printf("C: ");
  scanf("%d", &C);
  printf("D: ");
  scanf("%d", &D);
  printf("2^D: %f\n", power(2, D)); //Використовуємо степеневу функцію
  printf("C^3: %f\n", power(C, 3));
  printf("The result of calculation Q: %f\n", q(A, B, C, D)); //Вивід результату на екран

  return 1;
}

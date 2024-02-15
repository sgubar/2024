#include <stdio.h>
#include "dk_tool.h"

int main() {
  int a1, a2, a3, a4, b1, b2, b3, b4;
  printf("Enter elements for matrix A:\n");
  printf("a1: ");
  scanf("%d", &a1);
  printf("a2: ");
  scanf("%d", &a2);
  printf("a3: ");
  scanf("%d", &a3);
  printf("a4: ");
  scanf("%d", &a4);

  printf("Enter elements for matrix B:\n");
  printf("b1: ");
  scanf("%d", &b1);
  printf("b2: ");
  scanf("%d", &b2);
  printf("b3: ");
  scanf("%d", &b3);
  printf("b4: ");
  scanf("%d", &b4);

  int matrixA[2][2] = {{a1, a2}, {a3, a4}};
  int matrixB[2][2] = {{b1, b2}, {b3, b4}};

  multiply_matrices((int *)matrixA, 2, 2, (int *)matrixB, 2, 2); 
  return 0;
}

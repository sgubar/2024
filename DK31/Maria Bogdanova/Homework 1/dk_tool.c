#include "dk_tool.h"
#include <stdio.h>
#include <stdlib.h>

void multiply_matrices(int *matrix1, int nrow1, int ncol1, int *matrix2, int nrow2, int ncol2)
{ 
  int result[nrow1][ncol2];
  for (int i = 0; i < nrow1; i++) 
  {
    for (int j = 0; j < ncol2; j++) 
    {
      result[i][j] = 0;
      for (int k = 0; k < ncol1; k++) {
        result[i][j] += matrix1[i * ncol1 + k] * matrix2[k * ncol2 + j]; 
      }
    }
  }
  // Вивід результату на екран
 /// printf("Result of multiplication:\n");
  //for (int i = 0; i < nrow1; i++) {
   // for (int j = 0; j < ncol2; j++) {
     // printf("%d ", result[i][j]);
  //  }
   // printf("\n");
  //}
print_matrix(result, nrow1, ncol1);
}
int *create_matrix(int nrow, int ncol) {
  int *result = (int *)malloc(nrow * ncol * sizeof(int));//Використовується функція malloc для виділення пам'яті для матриці
  return result;
}

void destroy_matrix(int *matrix) {
  if (NULL == matrix) {
    return;
  }

  free(matrix); //Використовується функція free для звільнення пам'яті, яка була виділена раніше за допомогою malloc 
}

void print_matrix(int *matrix, int nrow, int ncol) {

  for (int i = 0; i < nrow; i ++) {
  for (int j = 0; j < ncol; j ++) {
    printf("%d ", *(matrix + nrow * i + j));}
   printf("\n");}}

void fill_matrix(int *matrix, int nrow, int ncol) {
  if (NULL == matrix) {
    return ;
  }

  for (int i = 0; i < nrow; i ++) {
    for (int j = 0; j < ncol; j ++) {
      *(matrix + nrow * i + j) = i + j;
    }
    printf("\n");
  }
}


int my_strlen(char *str) {
  int result = 0;
  int i = 0;

  while(*(str + i) != '\0') {
    i ++;
    result ++;
  }

  return result;
}

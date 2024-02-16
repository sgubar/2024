#include "dk_tools.h"
#include <stdio.h>
#include <cs50.h>
int *create_matrix(int r ,int c ){
  int *result = (int *)malloc(r * c * sizeof(int));
  return result;
}
int fill_matrix(int *matrix, int r , int c){
  if(NULL == matrix){
    return 0;
  }
  printf("Введіть елементи матриці : \n");
  for(int i = 0; i < r ; i++){
    for(int u = 0; u < c ; u++){
     printf("matrix[%d][%d] = ", i , u);
      int result = scanf("%d" , &matrix[i * c + u]);
      if (result != 1) {
          printf("Введіть число.\n");
          while (getchar() != '\n');
          u--;
      }
    }
  }
  printf("\n");
}


int otrimanya_rozmiru_matrix(int *r , int *c) {
    printf("Введіть кількість рядків : ");
    if (scanf("%d", r) != 1) {
        printf("Введено не число\n");
        return -1; 
    }

    printf("Введіть кількість стовчиків : ");
    if (scanf("%d", c) != 1) {
        printf("Введено не число\n");
        return -1;
    }

    return 0;
}


int *vid_matrix(int *m1 , int *m2 , int r , int c){
    int *result = (int *)malloc(r * c * sizeof(int));
    for(int i = 0; i < r ; i++){
      for(int u = 0; u < c ; u++){
        result[i*c +u] = m1[i * c + u]- m2[i*c + u ];
      }
    }
    return result ;
}

int print_matrix(int *matrix , int r , int c){
  if(NULL == matrix){
    return 0;
  }
  printf("Різниця матриць :\n");
  for(int i = 0; i < r ; i++){
    for(int u = 0; u < c ; u++){
      printf("%d ", matrix[i*c+u]);
    }  
    printf("\n");
  }
  return 0;
}

void destroy_matrix(int *matrix){
  if(NULL== matrix){
    return  ;
  }
  free(matrix);

}
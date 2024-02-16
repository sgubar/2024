#include <stdio.h>
#include "dk_tools.h"

int main() {
  int r = 0;
  int c = 0;

  otrimanya_rozmiru_matrix(&r, &c);
  
  int *matrix1 = create_matrix(r,c);
  fill_matrix(matrix1, r , c );
  int *matrix2 = create_matrix(r,c);
  fill_matrix(matrix2, r , c );
  int *rizn_matrix = vid_matrix(matrix1, matrix2 , r , c); 
  print_matrix(rizn_matrix, r , c);
  destroy_matrix(matrix1);
  destroy_matrix(matrix2);
  destroy_matrix(rizn_matrix);
    return 0;
}
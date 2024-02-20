#ifndef __dk_tool__
#define __dk_tool__

int** enter_matrix(int** matArr, int col, int row);
void print_matrix(int** mat, int col, int row);
void free_matrix(int** mat, int row);
void matrix_plus(int** mat1, int** mat2, int col, int row);
int** create_sapce(int** arr, int col, int row);

#endif

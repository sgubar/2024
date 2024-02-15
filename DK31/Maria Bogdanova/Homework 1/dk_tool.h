#ifndef DK_TOOL_H
#define DK_TOOL_H

void multiply_matrices(int *matrix1, int nrow1, int ncol1, int *matrix2, int nrow2, int ncol2); 

int *create_matrix(int nrow, int ncol); //творення матриці
void destroy_matrix(int *matrix); //ільнення пам'яті, яку використовує матриця

void print_matrix(int *matrix, int nrow, int ncol); //Виводить матрицю на екран

void fill_matrix(int *matrix, int nrow, int ncol); //Заповнює матрицю значеннями

int my_strlen(char *str); //Обчислює довжину рядка (стрічки). Приймає вказівник на рядок та повертає ціле число - довжину рядка

#endif

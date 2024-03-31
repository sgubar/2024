#ifndef DK_TOOL_H // Умовна компіляція для запобігання подвійному включенню
#define DK_TOOL_H

// Прототипи функцій для роботи з матрицями
void fillMatrix(int **matrix, int rows, int cols); // Заповнення матриці випадковими значеннями
void printMatrix(int **matrix, int rows, int cols); // Виведення матриці на екран
int **transposeMatrix(int **matrix, int rows, int cols); // Транспонування матриці
void freeMatrix(int **matrix, int rows); // Вивільнення пам'яті, виділеної під матрицю

#endif

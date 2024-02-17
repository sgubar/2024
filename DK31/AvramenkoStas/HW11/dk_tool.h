// Файл dk_tool.h
#ifndef DK_TOOL_H
#define DK_TOOL_H

// Функція для заповнення матриці довільними значеннями
void fillMatrix(int rows, int cols, int matrix[rows][cols]);

// Функція для виведення матриці на екран
void printMatrix(int rows, int cols, int matrix[rows][cols]);

// Функція для множення матриці на число
void multiplyMatrixByScalar(int rows, int cols, int matrix[rows][cols], int scalar);

#endif // DK_TOOL_H


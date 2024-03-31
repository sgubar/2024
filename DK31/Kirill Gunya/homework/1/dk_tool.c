#include "dk_tool.h"
#include <stdlib.h>
#include <stdio.h>

// Функція для заповнення матриці
void fillMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Простий спосіб заповнення для прикладу: сума індексів
            matrix[i][j] = i + j;
        }
    }
}

// Функція для виведення матриці на екран
void printMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Функція для транспонування матриці
int **transposeMatrix(int **matrix, int rows, int cols) {
    int **transposed = (int **)malloc(cols * sizeof(int *));
    for (int i = 0; i < cols; i++) {
        transposed[i] = (int *)malloc(rows * sizeof(int));
        for (int j = 0; j < rows; j++) {
            // Заміна рядків на стовпці
            transposed[i][j] = matrix[j][i];
        }
    }
    return transposed;
}

// Функція для вивільнення пам'яті
void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]); // Вивільнення пам'яті для кожного рядка
    }
    free(matrix); // Вивільнення пам'яті для вказівників на рядки
}

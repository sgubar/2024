// Файл dk_tool.c
#include <stdio.h>

// Функція для заповнення матриці введеними користувачем значеннями
void fillMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]); // Зчитування елемента матриці з клавіатури
        }
    }
}

// Функція для виведення матриці на екран
void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]); // Виведення елемента матриці
        }
        printf("\n"); // Перехід на новий рядок після виведення рядка матриці
    }
}

// Функція для множення кожного елемента матриці на задане число 
void multiplyMatrixByScalar(int rows, int cols, int matrix[rows][cols], int scalar) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] *= scalar; // Множення елемента матриці на скаляр
        }
    }
}

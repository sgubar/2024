#include "dk_tool.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows = 3, cols = 4; // Початкові розміри матриці для прикладу

    // Виділення пам'яті для матриці
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    fillMatrix(matrix, rows, cols); // Заповнення матриці
    printf("Original matrix:\n");
    printMatrix(matrix, rows, cols); // Виведення оригінальної матриці

    // Отримання та виведення транспонованої матриці
    int **transposed = transposeMatrix(matrix, rows, cols);
    printf("\nTransposed matrix:\n");
    printMatrix(transposed, cols, rows); // Враховуємо змінені розміри

    // Очищення пам'яті
    freeMatrix(matrix, rows);
    freeMatrix(transposed, cols);

    return 0;
}

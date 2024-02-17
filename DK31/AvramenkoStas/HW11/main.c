#include <stdio.h>
#include "dk_tool.h"

int main() {
    int rows, cols;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int matrix[rows][cols];

    // Заповнення матриці
    fillMatrix(rows, cols, matrix);

    // Виведення початкової матриці
    printf("Initial matrix:\n");
    printMatrix(rows, cols, matrix);

    // Множення матриці на число
    int scalar;
    printf("Enter a scalar to multiply by: ");
    scanf("%d", &scalar);
    multiplyMatrixByScalar(rows, cols, matrix, scalar);

    // Виведення зміненої матриці
    printf("Matrix after multiplication by scalar:\n");
    printMatrix(rows, cols, matrix);

    return 0;
}


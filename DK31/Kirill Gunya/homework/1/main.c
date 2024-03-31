#include "dk_tool.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows = 3, cols = 4; // �������� ������ ������� ��� ��������

    // �������� ���'�� ��� �������
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    fillMatrix(matrix, rows, cols); // ���������� �������
    printf("Original matrix:\n");
    printMatrix(matrix, rows, cols); // ��������� ���������� �������

    // ��������� �� ��������� ������������� �������
    int **transposed = transposeMatrix(matrix, rows, cols);
    printf("\nTransposed matrix:\n");
    printMatrix(transposed, cols, rows); // ��������� ����� ������

    // �������� ���'��
    freeMatrix(matrix, rows);
    freeMatrix(transposed, cols);

    return 0;
}

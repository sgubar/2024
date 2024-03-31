#include "dk_tool.h"
#include <stdlib.h>
#include <stdio.h>

// ������� ��� ���������� �������
void fillMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // ������� ����� ���������� ��� ��������: ���� �������
            matrix[i][j] = i + j;
        }
    }
}

// ������� ��� ��������� ������� �� �����
void printMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// ������� ��� �������������� �������
int **transposeMatrix(int **matrix, int rows, int cols) {
    int **transposed = (int **)malloc(cols * sizeof(int *));
    for (int i = 0; i < cols; i++) {
        transposed[i] = (int *)malloc(rows * sizeof(int));
        for (int j = 0; j < rows; j++) {
            // ����� ����� �� �������
            transposed[i][j] = matrix[j][i];
        }
    }
    return transposed;
}

// ������� ��� ���������� ���'��
void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]); // ���������� ���'�� ��� ������� �����
    }
    free(matrix); // ���������� ���'�� ��� ��������� �� �����
}

#ifndef DK_TOOL_H // ������ ��������� ��� ���������� ��������� ���������
#define DK_TOOL_H

// ��������� ������� ��� ������ � ���������
void fillMatrix(int **matrix, int rows, int cols); // ���������� ������� ����������� ����������
void printMatrix(int **matrix, int rows, int cols); // ��������� ������� �� �����
int **transposeMatrix(int **matrix, int rows, int cols); // �������������� �������
void freeMatrix(int **matrix, int rows); // ���������� ���'��, ������� �� �������

#endif

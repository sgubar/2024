#include "math_functions.h"
#include <stdio.h>

int main() {
    double A, B, C; // ���� ��� ������� �����
    double Q; // ����� ��� ����������

    // ����� �� �������� ������� ������ A, B � C
    printf("Enter value A: ");
    scanf("%lf", &A);
    printf("Enter value B (whole number): ");
    scanf("%lf", &B);
    printf("Enter value C: ");
    scanf("%lf", &C);

    // �������� �� ��'������ B ��� ���������
    if (B < 0) {
        printf("Enter an unknown number for B. Set B = 1.\n");
        B = 1;
    }

    // ��������� ��������� �� ��������
    Q = (power(A, 2) + power(B, 2)) / (B + power(5, C)) + factorial((int)B);

    // ���� ����������
    printf("Result Q = %lf\n", Q);

    return 0; // ������ ���������� ��������
}

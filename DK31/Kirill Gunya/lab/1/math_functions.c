#include "math_functions.h"

// ������� ��� ��������� ����� � ������
double power(double base, int exponent) {
    // ����������� ����������
    double result = 1;
    // ���������� ���������
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    // ������� ���������
    return result;
}

// ������� ��� ���������� ��������� �����
unsigned long long factorial(int n) {
    // ����������� ����������
    unsigned long long result = 1;
    // ���������� ���������
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    // ������� ���������
    return result;
}
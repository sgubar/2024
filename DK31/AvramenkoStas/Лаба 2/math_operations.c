// math_operations.c

#include "math_operations.h"
#include <math.h>

// Функція обчислення степеня
double power(double base, int exponent) {
    double result = 1.0;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

// Функція обчислення факторіалу
unsigned long long factorial(int n) {
    if (n == 0) return 1;
    unsigned long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Функція обчислення модуля числа
double absolute_value(double x) {
    return fabs(x);
}


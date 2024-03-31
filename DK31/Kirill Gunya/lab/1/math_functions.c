#include "math_functions.h"

// Функція для піднесення числа в степінь
double power(double base, int exponent) {
    // Ініціалізація результату
    double result = 1;
    // Позитивний експонент
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    // Вертаємо результат
    return result;
}

// Функція для обчислення факторіалу числа
unsigned long long factorial(int n) {
    // Ініціалізація результату
    unsigned long long result = 1;
    // Обчислення факторіалу
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    // Вертаємо результат
    return result;
}
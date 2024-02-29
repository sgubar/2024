// main.c

#include <stdio.h>
#include "math_operations.h"

int main() {
    int A, B;
    double Q;

    // Введення значення змінної A
    printf("Введіть значення змінної A (ціле число): ");
    if (scanf("%d", &A) != 1) {
        printf("Помилка: введено некоректне значення для A.\n");
        return 1;
    }

    // Перевірка на недопустимі значення для A
    if (A < 0) {
        printf("Помилка: A повинно бути не менше 0.\n");
        return 1;
    }

    // Введення значення змінної B
    printf("Введіть значення змінної B (ціле число): ");
    if (scanf("%d", &B) != 1) {
        printf("Помилка: введено некоректне значення для B.\n");
        return 1;
    }

    // Обчислення виразу
    double denominator = absolute_value(2.0 * A + B);
    if (denominator == 0) {
        printf("Помилка: ділення на нуль.\n");
        return 1;
    }

    Q = factorial(A) / denominator;

    // Виведення результату
    printf("Результат: Q = %.2f\n", Q);

    return 0;
}


#include "math_functions.h"
#include <stdio.h>

int main() {
    double A, B, C; // Змінні для входних даних
    double Q; // Змінна для результату

    // Запит на введення значень змінних A, B і C
    printf("Enter value A: ");
    scanf("%lf", &A);
    printf("Enter value B (whole number): ");
    scanf("%lf", &B);
    printf("Enter value C: ");
    scanf("%lf", &C);

    // Перевірка на від'ємність B для факторіала
    if (B < 0) {
        printf("Enter an unknown number for B. Set B = 1.\n");
        B = 1;
    }

    // Виконання обчислень за формулою
    Q = (power(A, 2) + power(B, 2)) / (B + power(5, C)) + factorial((int)B);

    // Вивід результату
    printf("Result Q = %lf\n", Q);

    return 0; // Успішне завершення програми
}

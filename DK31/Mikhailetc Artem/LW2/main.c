#include <stdio.h>
#include "math.h"

int get_int_input(const char *message);

int main() {
    int A, B, C;
    double Q;

    A = get_int_input("Введіть значення A: ");
    B = get_int_input("Введіть значення B: ");
    C = get_int_input("Введіть значення C: ");

    Q = calculate_Q(A, B, C);
    printf("Q = %.2f\n", Q);

    return 0;
}

int get_int_input(const char *message) {
    int input;
    char buffer[100];

    while (1) {
        printf("%s", message);
        fgets(buffer, sizeof(buffer), stdin);
        if (sscanf(buffer, "%d", &input) == 1) {
            break;
        } else {
            printf("Некоректне введення. Будь ласка, введіть ціле число.\n");
            while (getchar() != '\n');
        }
    }

    return input;
}

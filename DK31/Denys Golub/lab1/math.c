#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "math.h"

long compute_factorial(int n) {
    long res = 1;

    if (n < 0) {
        return -1;
    }
    for (int i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

long sum_of_factorials(int start, int end) {
    long total = 0;

    for (int i = start; i <= end; i++) {
        total += compute_factorial(i + end);
    }
    return total;
}

void validate_input(int* num) {
    while (scanf_s("%d", num) != 1) {
        printf("Invalid input, please enter a number: ");
        while (getchar() != '\n') {}
    }
}

void validate_nonzero_input(int* num) {
    while (scanf_s("%d", num) != 1 || *num == 0) {
        printf("Invalid input, please enter a non-zero number: ");
        while (getchar() != '\n') {}
    }
}

void validate_sum_positive(int* B, int* C) {
    if (*B + *C <= 0) {
        printf("Invalid input, B + C < 0\n");
        printf("Please enter a number for B: \n");
        validate_input(B);
        printf("Please enter a number for C: \n");
        validate_input(C);
    }
}

void validate_sum_nonnegative(int* A, int* C) {
    if (*A + *C < 0) {
        printf("Invalid input, A + C < 0\n");
        printf("Please enter a number for A: \n");
        validate_input(A);
        printf("Please enter a number for C: \n");
        validate_input(C);
    }
}

double compute_expression(int x, int y, int z) {
    int D = 0;
    double result = x * (sqrt(y + z) / y) + sum_of_factorials(D, x);
    return result;
}

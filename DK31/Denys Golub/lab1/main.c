#include <stdio.h>
#include <math.h>
#include "math.h"

int main(int argc, const char* argv[]) {

    int A, B, C;

    printf("Enter A: ");
    validate_input(&A);
    printf("Enter B (not equal to 0): ");
    validate_nonzero_input(&B);
    printf("Enter C: ");
    validate_input(&C);

    validate_sum_positive(&B, &C);
    validate_sum_nonnegative(&A, &C);

    printf("Your data: \n");
    printf("%d\n", A);
    printf("%d\n", B);
    printf("%d\n", C);

    double result = compute_expression(A, B, C);
    printf("Result: %.2lf\n", result);

    return 0;
}

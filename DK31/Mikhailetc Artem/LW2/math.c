#include "math.h"
#include <stdlib.h>

float my_sqrt(float n) {
    float x = n;
    float y = 1;
    float e = 0.000001; 

    while (x - y > e) {
        x = (x + y) / 2;
        y = n / x;
    }
    return x;
}

int my_factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * my_factorial(n - 1);
}

double calculate_Q(int A, int B, int C) {
    double Q = A * (my_sqrt(B + C) / B);
    int D;
    for (D = 0; D <= C; D++) {
        Q += my_factorial(A + D);
    }
    return Q;
}
#include "my_math.h"
#include <stdio.h>

int main(void) {
    float *a_and_b;

    printf("Enter numbers A and B.\n"
           "A must be a nonnegative integer.\n"
           "The mathematical expression\n"
           "         A * 2 + B = 0\n"
           "must be false.\n\n");

    // read A and B
    a_and_b = read_AB();

    // print result
    printf("A! / |A*2 + B| = %f\n", calc((int) a_and_b[0], a_and_b[1]));

    // clean memory
    destroy_nums(a_and_b);
    return 0;
}

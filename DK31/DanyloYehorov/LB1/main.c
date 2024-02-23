#include "my_math.h"
#include <stdio.h>

int main(void) {
    int a;
    float b;

    // read A and B
    read_AB(&a, &b);

    // print result
    printf("A! / |A*2 + B| = %f\n", calc(a, b));

    return 0;
}

#include <stdio.h>
#include "array.h"


int main(void) {
    Trapezium *tr1 = createTrapeziumFromCords(-3, -3, 5, 1, 10, -2, -4, -9);
    Trapezium *tr2 = createTrapeziumFromCords(2,   3, 4, 3,  5,  1,  1,  1);
    Trapezium *tr3 = createTrapeziumFromCords(1,   1, 2, 1,  3,  0,  0,  0);

    Array *ar = createArray(2);

    addTrapeziumToArray(ar, tr1);
    addTrapeziumToArray(ar, tr2);

    printf("Befor extending: ");
    printArray(ar);

    addTrapeziumToArray(ar, tr3);
    printf("\nAfter extending: ");
    printArray(ar);

    addTrapeziumAtIndex(ar, tr3, 0);
    printf("\nAfter adding at index: ");
    printArray(ar);
    printf("\n");

    destroyTrapezium(tr1);
    destroyTrapezium(tr2);
    destroyTrapezium(tr3);
    destroyArray(ar);

    return 0;
}

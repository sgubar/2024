#include <stdio.h>
#include "trapezium.h"

void printTrapeziumInfo(Trapezium *tr);

int main(void) {
    // (-3, -3), (5, 1), (10, -2), (-4, -9)
    // ( 2,  3), (4, 3), (5,   1), ( 1,  1)

    Trapezium *tr = getTrapezium();
    printTrapeziumInfo(tr);
    destroyTrapezium(tr);

    return 0;
}


void printTrapeziumInfo(Trapezium *tr) {
    printf("Trapezium is %s.\n", (validateTrapezium(tr) ? "valid" : "invalid"));
    printTrapeziumPoints(tr);
    printf("Area of trapezium: %f\n", areaOfTrapezium(tr));
}

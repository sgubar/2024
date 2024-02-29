#ifndef _trapezium_h_
#define _trapezium_h_
#include "point.h"

typedef struct tagTrapezium {
    Point *A;
    Point *B;
    Point *C;
    Point *D;
} Trapezium;

Trapezium *createTrapeziumFromArray(Point points[]);
Trapezium *createTrapeziumFromPtrArray(Point *points[]);
Trapezium *createTrapeziumFromCords(float ax, float ay, float bx, float by, float cx, float cy, float dx, float dy);
Trapezium * getTrapezium();

float areaOfTrapezium(Trapezium *tr);
void printTrapeziumPoints(Trapezium *tr);
int validateTrapezium(Trapezium *tr);
void destroyTrapezium(Trapezium *tr);

#endif

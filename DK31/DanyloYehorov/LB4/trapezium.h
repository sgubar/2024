#ifndef _trapezium_h_
#define _trapezium_h_

#include "point.h"

typedef struct tagColorProps {
    float red;
    float green;
    float blue;
} ColorProps;


typedef struct tagTrapezium {
    Point *A;
    Point *B;
    Point *C;
    Point *D;

    ColorProps color;
} Trapezium;

Trapezium *createTrapeziumFromCords(float ax, float ay, float bx, float by, float cx, float cy, float dx, float dy, ColorProps color);
int validateTrapezium(Trapezium *tr);
void destroyTrapezium(Trapezium *tr);
ColorProps createColor(float red, float green, float blue);
void drawTrapezium(Trapezium *tr);

#endif

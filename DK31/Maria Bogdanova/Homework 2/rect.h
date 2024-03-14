#ifndef _rect_h_
#define _rect_h_
#include "point.h"

typedef struct tagRectangle {
    Point *A;
    Point *C;
} Rectangle;


Rectangle createRectangle(Point *A, Point *C);
double calculateRectangleArea(Rectangle *R);
void destroyRectangle(Rectangle *R);
void printResult(Rectangle *R);

#endif

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "point.h"

struct Rectangle {
    Point topLeft;     
    Point bottomRight; 
};

Rectangle* createRectangle(double x1, double y1, double x2, double y2);
void destroyRectangle(Rectangle* rect);
void printRectangle(Rectangle* rect);

#endif /* RECTANGLE_H */

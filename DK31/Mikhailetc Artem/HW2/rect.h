#ifndef RECT_H
#define RECT_H

#include "point.h"

struct Rectangle {
    Point topLeft;     
    Point bottomRight; 
};

Rectangle* createRectangle(Point* points, int size);
void destroyRectangle(Rectangle* rect);
double calculateArea(Rectangle* rect);
void printRectangle(Rectangle* rect);

#endif // RECT_H

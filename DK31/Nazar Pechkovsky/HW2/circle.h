//
// Created by Nazar Pechkovsky on 10.03.2024.
//

#ifndef HW2_CIRCLE_H
#define HW2_CIRCLE_H

#include "point.h"

typedef struct tagCircle
{
    Point *pCen;
    Point *pCir;
} Circle;

Point *createCords();
float calculateRadius(Circle *circle);
Circle *createCircleByPoints(Point *O, Point *K);
float calculateCircleArea(Circle *circle, float radius);
float calculateCirclePerimeter(Circle *circle, float radius);
void destroyCircle(Circle *circle);
void checkCods(float num);

#endif //HW2_CIRCLE_H

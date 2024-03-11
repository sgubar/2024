//
// Created by Nazar Pechkovsky on 10.03.2024.
//

#ifndef HW2_POINT_H
#define HW2_POINT_H

typedef struct tPoint
{
    float x;
    float y;
} Point;

Point* createPoint(float x, float y);
void destroyPoint(Point* p);
void printPoint(Point* p);



#endif //HW2_POINT_H

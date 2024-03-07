#ifndef _point_h_
#define _point_h_

typedef struct tagPoint {
    float x;
    float y;
} Point, *PPoint;

Point *createPoint(float x, float y);
void destroyPoint(Point *Point);
void printPoint(Point *P);

#endif

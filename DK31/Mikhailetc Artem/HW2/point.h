#ifndef point_h
#define point_h

#include <stdio.h>

typedef struct tagPoint {
  int x;
  int y;
} Point, *PPoint; ч

Point *createPoint(int x, int y);
void destroyPoint(Point *P); 
void printPoint(Point *P); 

#endif

#ifndef point_h
#define point_h

#include <stdio.h>

struct tagPoint {
	int x;
	int y;
};
typedef struct tagPoint Point;

Point *createPoint(int x, int y);
Point *copyPoint(Point *a);
void destroyPoint(Point *a);
void printPoint(Point *a);
void fillPoint(Point *a);
void setPointValues(Point* point, int x, int y);

#endif

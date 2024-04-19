


#ifndef point_h
#define point_h

#include <stdio.h>

struct tagPoint {
	float x;
	float y;
};
typedef struct tagPoint Point;

Point *createPoint(float x, float y);
Point *copyPoint(Point *a);
void deletePoint(Point *a);
void printPoint(Point *a);
void fillPoint(Point *a);
void setPointValues(Point* point, float x, float y);

#endif /* point_h */

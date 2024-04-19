

#include "point.h"
#include <stdlib.h>

void printPoint(Point *a)
{
	if (NULL != a) {
		printf("{ x:%d, y:%d}", a->x, a->y);
	}
}

void fillPoint(Point *a)
{
	if (NULL != a) {
		a->x = 50;
		a->y = 30;
	}
}

Point *createPoint(float x, float y)
{
	Point *result = (Point *)malloc(sizeof(Point));
	if (NULL != result) {
		result->x = x;
		result->y = y;
	}

	return result;
}

Point *copyPoint(Point *a) {
	if (NULL == a) {
		return NULL;
	}

	return createPoint(a->x, a->y);
}

void deletePoint(Point *a) {
	if (NULL != a) {
		free(a);
	}
}

void setPointValues(Point* point, float x, float y){
    if (NULL != point) {
		point->x = x;
		point->y = y;
	}
}

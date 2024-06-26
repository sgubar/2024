#include "point.h"
#include <stdlib.h>

Point* createPoint(int x, int y) {
    Point* point = (Point*)malloc(sizeof(Point));
    if (point != NULL) {
        point->x = x;
        point->y = y;
    }
    return point;
}

void destroyPoint(Point* aPoint) {
    if (aPoint != NULL) {
        free(aPoint);
    }
}

void printPoint(Point* aPoint) {
    if (aPoint == NULL) {
        printf("Invalid object");
        return;
    }
    printf("{%d, %d}", aPoint->x, aPoint->y);
}

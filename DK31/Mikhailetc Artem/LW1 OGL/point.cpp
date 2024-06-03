#include "point.h"
#include <stdlib.h>

// створення точки з заданими координатами
Point* createPoint(int x, int y) {
    Point* point = (Point *)malloc(sizeof(Point));

    if (point != NULL) {
        point->x = x;
        point->y = y;
    }

    return point;
}

// видалення пам'яті, виділеної для точки
void deletePoint(Point *point) {
    if (point != NULL) {
        free(point);
    }
}

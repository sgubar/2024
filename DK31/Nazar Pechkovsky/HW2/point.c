//
// Created by Nazar Pechkovsky on 10.03.2024.
//

#include "point.h"
#include <malloc.h>
#include <stdio.h>

Point* createPoint(float x, float y) //Створюємо точку
{
    Point* result = (Point *)malloc(sizeof(Point));
    if (NULL != result) {
        result->x = x;
        result->y = y;
    }

    return result;
}

void destroyPoint(Point *P) //Видаляємо точку
{
    if (P != NULL) {
        free(P);
    }
}

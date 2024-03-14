#include "point.h"
#include <stdlib.h>
#include <stdio.h>

Point *createPoint(int x, int y) {
    Point *result = (Point *) malloc(sizeof(Point));

    if (result != NULL) {
        result->x = x;
        result->y = y;
    }
    return result;
}

void destroyPoint(Point *P) {
    if (P != NULL) {
        free(P);
    }
}

void printPoint(Point *P) {
    if (P == NULL) {
        printf("Invalide reference to point");
        return;
    }
    printf("(%d, %d)", P->x, P->y);
}

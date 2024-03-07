#include "point.h"
#include <stdlib.h>
#include <stdio.h>

Point *createPoint(float x, float y) {
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
        P = NULL;
    }
}


void printPoint(Point *P) {
    if (P == NULL) {
        printf("Invalide reference to point");
        return;
    }
    printf("(%.2f, %.2f)", P->x, P->y);
}

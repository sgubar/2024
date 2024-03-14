#include "point.h"
#include <stdlib.h>
#include <stdio.h>

Point *createPoint(int x, int y) {
    Point *result = (Point *) malloc(sizeof(Point)); //виділяємо пам'ять для структури

    if (result != NULL) { //перевірка чи result не нуль
        result->x = x; // це значення буде скопійовано у поле х
        result->y = y; //це значення буде скопійовано у поле у
    }
    return result;
}

void destroyPoint(Point *P) {
    if (P != NULL) { //перевірка чи Р не нуль
        free(P); //звільняємо пам'ять 
    }
}

void printPoint(Point *P) { 
    if (P == NULL) { 
        printf("Invalide reference to point");
        return;
    }
    printf("(%d, %d)", P->x, P->y); //виводимо координати
}

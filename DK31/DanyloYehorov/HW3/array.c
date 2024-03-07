#include "array.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void extendInternalStorage(Array *ar);

Array *createArray(unsigned int preserved) {
    if (preserved <= 0) {
        return NULL;
    }

    // get memory for array
    Array *result = (Array *) malloc(sizeof(Array));

    if (NULL != result) {
        result->preserved = preserved;
        result->storage = (Trapezium **) malloc(sizeof(Trapezium *) * result->preserved);
        result->lastElement = 0;
    }

    return result;
}



void destroyArray(Array *ar) {
    if (ar == NULL) {
        return;
    }

    // destory Trapeziums
    unsigned int i;
    for (i = 0; i < ar->lastElement; i++) {
        destroyTrapezium(getTrapeziumAtIndex(ar, i));
    }

    // destory storage
    free(ar->storage);

    // destoroy pointer to storage
    free(ar);
    ar = NULL;
}



void addTrapeziumToArray(Array *ar, Trapezium  *tr) {
    if (ar == NULL || tr == NULL) {
        return;
    }

    // if storage exhausted
    if (ar->lastElement == ar->preserved) {
        // extend storage
        extendInternalStorage(ar);
        if (ar->lastElement == ar->preserved) {
            // array not extended -> something wrong
            return;
        }
    }

    // create new trapezium
    Trapezium *tempTr = createTrapeziumFromCords(tr->A->x, tr->A->y, tr->B->x, tr->B->y,
                                                 tr->C->x, tr->C->y, tr->D->x, tr->D->y);

    // add pointer to new trapezium

    ar->storage[ar->lastElement] = tempTr;
    ar->lastElement++;
}



Trapezium *getTrapeziumAtIndex(Array *ar, unsigned int index) {
    if (ar == NULL && index >= ar->lastElement) {
        return NULL;
    }

    return ar->storage[index];
}



void addTrapeziumAtIndex(Array *ar, Trapezium  *tr, unsigned int index) {
    if (ar == NULL || tr == NULL || index < 0 || index >= ar->preserved) {
        return;
    }

    // clear cell
    destroyTrapezium(getTrapeziumAtIndex(ar, index));

    // create new trapezium
    Trapezium *tempTr = createTrapeziumFromCords(tr->A->x, tr->A->y, tr->B->x, tr->B->y,
                                                 tr->C->x, tr->C->y, tr->D->x, tr->D->y);

    // add pointer to new trapezium
    ar->storage[ar->lastElement] = tempTr;

    // set new last element (if necessary)
    if (index > ar->lastElement) {
        ar->lastElement = index;
    }
}



void extendInternalStorage(Array *ar) {
    Trapezium **newStorage = (Trapezium **) malloc(sizeof(Trapezium *) * ar->preserved * 2);

    if (newStorage == NULL) {
        return;
    }

    memcpy(newStorage, ar->storage, sizeof(Trapezium *) * ar->preserved);

    free(ar->storage);
    ar->storage = newStorage;
    ar->preserved *= 2;
}



void printArray(Array *ar) {
    if (ar == NULL) {
        printf("(NULL)");
    }

    unsigned int i;
    printf("[");
    for (i = 0; i < ar->lastElement - 1; i++) {
        printTrapeziumPoints(getTrapeziumAtIndex(ar, i));
        printf("]-[");
    }
    printTrapeziumPoints(getTrapeziumAtIndex(ar, i));
    printf("]");
}

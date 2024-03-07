#ifndef _array_h_
#define _array_h_

#include "trapezium.h"

typedef struct tagArray {
    Trapezium **storage;
    unsigned int preserved;
    unsigned int lastElement;
} Array;

Array *createArray(unsigned int preserved);
void destroyArray(Array *ar);

void addTrapeziumToArray(Array *ar, Trapezium  *tr);
Trapezium *getTrapeziumAtIndex(Array *ar, unsigned int index);
void addTrapeziumAtIndex(Array *ar, Trapezium  *tr, unsigned int index);

void printArray(Array *ar);

#endif

#ifndef ARRAYOFRECTANGLE_H
#define ARRAYOFRECTANGLE_H

#include "rectangle.h"

struct Array {
    Rectangle** elements; 
    int size;             
    int capacity;         
};

struct Array* createArray(int capacity);
void destroyArray(struct Array* arr);
int addElement(struct Array* arr, Rectangle* rect);
int insertElement(struct Array* arr, Rectangle* rect, int index);
void printArray(struct Array* arr);

#endif /* ARRAYOFRECTANGLE_H */

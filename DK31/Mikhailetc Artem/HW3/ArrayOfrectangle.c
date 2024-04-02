#include "ArrayOfrectangle.h"
#include <stdio.h>
#include <stdlib.h>

struct Array* createArray(int capacity) {
    struct Array* arr = (struct Array*)malloc(sizeof(struct Array));
    if (arr == NULL) {
        printf("Не вдалося виділити пам'ять для масиву.\n");
        return NULL;
    }
    
    arr->elements = (Rectangle**)malloc(capacity * sizeof(Rectangle*));
    if (arr->elements == NULL) {
        printf("Не вдалося виділити пам'ять для елементів масиву.\n");
        free(arr);
        return NULL;
    }
    
    arr->size = 0;
    arr->capacity = capacity;
    return arr;
}

void destroyArray(struct Array* arr) {
    if (arr == NULL) return;
    
    for (int i = 0; i < arr->size; i++) {
        destroyRectangle(arr->elements[i]);
    }
    free(arr->elements);
    free(arr);
}

int addElement(struct Array* arr, Rectangle* rect) {
    if (arr == NULL || rect == NULL) return -1;
    if (arr->size >= arr->capacity) {
        printf("Масив заповнений. Неможливо додати новий елемент.\n");
        return -1;
    }
    
    arr->elements[arr->size] = rect;
    arr->size++;
    return arr->size - 1;
}

int insertElement(struct Array* arr, Rectangle* rect, int index) {
    if (arr == NULL || rect == NULL || index < 0 || index > arr->size) return -1;
    if (arr->size >= arr->capacity) {
        printf("Масив заповнений. Неможливо додати новий елемент.\n");
        return -1;
    }
    
    for (int i = arr->size; i > index; i--) {
        arr->elements[i] = arr->elements[i - 1];
    }
    arr->elements[index] = rect;
    arr->size++;
    return index;
}

void printArray(struct Array* arr) {
    if (arr == NULL) return;
    
    printf("Масив прямокутників:\n");
    for (int i = 0; i < arr->size; i++) {
        printf("Елемент %d: ", i);
        printRectangle(arr->elements[i]);
    }
}

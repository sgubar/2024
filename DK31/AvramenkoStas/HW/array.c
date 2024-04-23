#include <stdio.h>
#include <stdlib.h>
#include "array.h"

// Функція створення масиву на певну кількість елементів
struct Array* create_array(int num_elements) {
    struct Array* arr = (struct Array*)malloc(sizeof(struct Array));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    arr->size = 0;
    arr->capacity = num_elements;
    arr->shapes = (struct Shape*)malloc(num_elements * sizeof(struct Shape));
    if (arr->shapes == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    return arr;
}


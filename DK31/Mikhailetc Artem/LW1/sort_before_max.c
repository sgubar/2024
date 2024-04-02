#include "sort_before_max.h"
#include <stdio.h>
#include <stdlib.h>

int* createArray(int size) {
    if (size <= 0) {
        printf("Помилка: недійсний розмір масиву.\n");
        return NULL;
    }

    int *array = (int*)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Помилка виділення пам'яті.");
        return NULL;
    }

    return array;
}

void inputArrayElements(int array[], int size) {
    printf("Введіть елементи масиву: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
}

int findMaxIndex(int array[], int size) {
    int max_index = 0;
    for (int i = 1; i < size; i++) {
        if (array[i] > array[max_index]) {
            max_index = i;
        }
    }
    return max_index;
}

void sortAscending(int array[], int max_index) {
    for (int i = 0; i < max_index - 1; i++) {
        for (int j = i + 1; j < max_index; j++) {
            if (array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void sortArrayBeforeMax(int array[], int size) {
    int max_index = findMaxIndex(array, size);
    sortAscending(array, max_index);
}





void freeArray(int *ptr) {
    if (ptr != NULL) {
        free(ptr);
        ptr = NULL; 
    }
}

void printArrayElements(int array[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

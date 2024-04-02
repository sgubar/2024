#include "sort_before_max.h"
#include <stdio.h>

int main() {
  int size;
  printf("Введіть розмір масиву: ");
  scanf("%d", &size);

  int *array = createArray(size);
  if (array == NULL) {
    return 1;
  }

  inputArrayElements(array, size);

  printf("Початковий масив: ");
  printArrayElements(array, size);

  sortArrayBeforeMax(array, size);

  printf("Вихідний Масив : ");
  printArrayElements(array, size);

  freeArray(array);

  return 0;
}

#include <stdio.h>
#include <stdlib.h> // Для використання функції free()
#include "array.h"

int main() {
    int capacity;
    printf("Enter the capacity of the array: ");
    scanf("%d", &capacity);

    struct Array* myArray = create_array(capacity);

    printf("Array created with capacity %d\n", myArray->capacity);

    // Очищення пам'яті
    free(myArray->shapes); // Вільна пам'ять, виділена для масиву фігур
    free(myArray); // Вільна пам'ять, виділена для структури масиву

    return 0;
}


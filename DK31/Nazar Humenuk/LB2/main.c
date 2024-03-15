#include <stdio.h>
#include <stdlib.h>
#include "list_double.h"

int main(void) {
    ListDoubl *List = fillListDoubl();//створюємо список
    printf("Cписок до видалення кожного третього елементу : \n");
    printListDoubl(List);
    printf("Видалення кожного третього елементу : \n");
    deleteEvryThirdElementInList(List);// виконуємо нашу функцію для видалення кожного третього елементу
    printf("Cписок після видалення кожного третього елементу : \n");
    printListDoubl(List);//виводимо список
    destroyListDoubl(List);//видаляємо список

    return 0;
}
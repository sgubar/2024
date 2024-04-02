#include <stdio.h>
#include "LinkedList.h"

int main() {
    struct LinkedList* list = createList();

    addNode(list, 5);
    addNode(list, 10);
    addNode(list, 15);

    printf("Список: ");
    printList(list);
    printf("\n");

    insertNode(list, 7, 1);
    printf("Після вставки елементу зі значенням 7 на позицію 1: ");
    printList(list);
    printf("\n");

    deleteNode(list, 10);
    printf("Після видалення елементу зі значенням 10: ");
    printList(list);
    printf("\n");

    printf("Розмір списку: %d\n", getListSize(list));

    deleteList(list);

    return 0;
}

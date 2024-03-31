#include <stdio.h>
#include "list.h"

void generalTests(void);
void boundaryTests(void);

int main(void) {
    generalTests(); // Выполнение общих тестов
    boundaryTests(); // Выполнение граничных тестов

    return 0;
}

void generalTests(void) {
    printf("//------- GENERAL TESTS -------//\n\n");

    List *list = createList();
    printf("List created. Size: %d\n", listSize(list));

    appendToList(list, 10);
    appendToList(list, 20);
    appendToList(list, 30);
    printf("Three numbers appended to list. Size: %d\n", listSize(list));
    printList(list);

    insertToList(list, 1, 15);
    printf("Number 15 inserted at index 1. Size: %d\n", listSize(list));
    printList(list);

    removeFromList(list, 1);
    printf("Number at index 1 removed. Size: %d\n", listSize(list));
    printList(list);

    destroyList(list);
    printf("List destroyed.\n");
}

void boundaryTests(void) {
    printf("\n//------- BOUNDARY TESTS -------//\n\n");

    List *list = createList();

    removeFromList(list, 0);
    printf("Attempted to remove from empty list. Size: %d\n", listSize(list));
    printList(list);

    appendToList(list, 10);
    appendToList(list, 20);
    removeFromList(list, 5);
    printf("Attempted to remove from index 5. Size: %d\n", listSize(list));
    printList(list);

    insertToList(list, 3, 50);
    printf("Attempted to insert number 50 at index 3. Size: %d\n", listSize(list));
    printList(list);

    insertToList(list, 1, 35);
    printf("Number 35 inserted at index 1. Size: %d\n", listSize(list));
    printList(list);

    destroyList(list);
    printf("List destroyed.\n");
}

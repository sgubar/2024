#include <stdio.h>
#include "list.h"

void generalTests(void);
void oorTests(void);

int main(void) {
    generalTests();
    oorTests();

    return 0;
}

void oorTests(void) {
    List *l = createList();

    printf("//------- OUT-OF-RANGE TESTS -------//\n\n");

    appendNumberToList(l, 2.3);
    appendNumberToList(l, 4.2);
    appendNumberToList(l, 5.1);

    //---------------------------
    printf("Deleting out of range (10):\nBefore");
    printf(" | size: %d | ", listSize(l));
    printList(l);

    deleteNumberFromList(l, 10);

    printf("\nAfter ");
    printf(" | size: %d | ", listSize(l));
    printList(l);

    //---------------------------
    printf("\n\nInserting out of range (10):\nBefore");
    printf(" | size: %d | ", listSize(l));
    printList(l);

    insertNumberToList(l, 10, 0.1);

    printf("\nAfter ");
    printf(" | size: %d | ", listSize(l));
    printList(l);

    printf("\n\n");

    destroyList(l);
}

void generalTests(void) {
    List *l = NULL;

    printf("//------- GENERAL TESTS -------//\n\n");

    //---------------------------
    printf("Creation:\nBefore");
    printf(" | size: %u | ", listSize(l));
    printList(l);

     l = createList();

    printf("\nAfter ");
    printf(" | size: %d | ", listSize(l));
    printList(l);

    //---------------------------
    printf("\n\nAppending:\nBefore");
    printf(" | size: %d | ", listSize(l));
    printList(l);

    appendNumberToList(l, 2.3);
    appendNumberToList(l, 4.2);
    appendNumberToList(l, 5.1);
    appendNumberToList(l, 6.9);

    printf("\nAfter ");
    printf(" | size: %d | ", listSize(l));
    printList(l);

    //---------------------------
    printf("\n\nDeleting (index=0, first):\nBefore");
    printf(" | size: %d | ", listSize(l));
    printList(l);

    deleteNumberFromList(l, 0);

    printf("\nAfter ");
    printf(" | size: %d | ", listSize(l));
    printList(l);

    //---------------------------
    printf("\n\nDeleting (index=1):\nBefore");
    printf(" | size: %d | ", listSize(l));
    printList(l);

    deleteNumberFromList(l, 1);

    printf("\nAfter ");
    printf(" | size: %d | ", listSize(l));
    printList(l);

    //---------------------------
    printf("\n\nDeleting (index=1, last) and appending:\nBefore");
    printf(" | size: %d | ", listSize(l));
    printList(l);

    deleteNumberFromList(l, 1);
    appendNumberToList(l, 2.3);

    printf("\nAfter ");
    printf(" | size: %d | ", listSize(l));
    printList(l);

    //---------------------------
    printf("\n\nInserting (index=0, first):\nBefore");
    printf(" | size: %d | ", listSize(l));
    printList(l);

    insertNumberToList(l, 0, 0.6);

    printf("\nAfter ");
    printf(" | size: %d | ", listSize(l));
    printList(l);

    //---------------------------
    printf("\n\nInserting (index=1):\nBefore");
    printf(" | size: %d | ", listSize(l));
    printList(l);

    insertNumberToList(l, 1, 9.9);

    printf("\nAfter ");
    printf(" | size: %d | ", listSize(l));
    printList(l);

    printf("\n\n");

    destroyList(l);
}

#include <stdio.h>
#include "list.h"

int main(void) {
    List *l = getListFromUser();
    printf("Before clear:\n");
    printList(l);
    printf("\n\nAfter clear:\n");

    deleteDuplicates(l);

    printList(l);
    printf("\n");

    return 0;
}

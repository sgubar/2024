#include <stdio.h>
#include "linkedlist.h"

int main() {
    Node* head = NULL;

    add_element(&head, 1);
    add_element(&head, 2);
    add_element(&head, 6);
    add_element(&head, 4);

    printf("Size of the list: %d\n", size(head));
    printf("List: ");
    display(head);

    insert_element(&head, 1, 5);
    printf("After inserting : ");
    display(head);

    remove_element(&head, 2);
    printf("After removing : ");
    display(head);

    delete_list(&head);
    printf("After deleting the list: ");
    display(head);

    return 0;
}


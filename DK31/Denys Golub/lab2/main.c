#include <stdio.h>
#include <stdlib.h>
#include "line.h"

int main() {
    Node *head = NULL;

    int n, data;
    printf("Enter the number of elements: ");
    stop_stupid(&n);

    print_elements(&n, &data, &head);

    
    printf("Iteration:\n");
    print_list(head);
    turns_list(&head);

    

    printf("Reversed iteration:\n");
    print_list(head);
    turns_list(&head);
    

    printf("Iteration:\n");
    print_list(head);
    turns_list(&head);

    printf("Reversed iteration:\n");
    print_list(head);
    delete_list(&head);


    return 0;
}

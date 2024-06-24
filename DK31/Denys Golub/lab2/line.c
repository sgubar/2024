#include <stdio.h>
#include <stdlib.h>
#include "line.h"

Node *create_node(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

void stop_stupid(int *n) {
    while(scanf_s("%d", n) != 1 ) {
        printf("Invalid input, try again: ");
        while (getchar() != '\n') {}
    }
}


void print_elements(int *n, int *data, Node **head){
    for (int i = 0; i < *n; i++) {
        printf("Enter element %d: ", i + 1);
        stop_stupid(data);
        append(head, *data);
    }
}

void print_list(Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void append(Node **head_ref, int data) {
    Node *new_node = create_node(data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    Node *current = *head_ref;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    new_node->prev = current;
}



void turns_list(Node **head_ref) {
    if (*head_ref != NULL) {
    Node *current = *head_ref;
    Node *prev = NULL;
    Node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        current->prev = next; 
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

}

void delete_list(Node **head_ref) {
    turns_list(head_ref);
    Node *current = *head_ref;
    while (current != NULL) {
        Node *temp = current->next;
        free(current);
        current = temp;
    }
    *head_ref = NULL;
}




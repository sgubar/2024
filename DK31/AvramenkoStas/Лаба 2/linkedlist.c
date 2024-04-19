#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

// Функція для створення нового вузла
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Функція для виведення списку
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Функція для вставки елемента у відсортований список
void insertSorted(struct Node** head_ref, int data) {
    struct Node* new_node = newNode(data);
    if (*head_ref == NULL || (*head_ref)->data >= data) {
        new_node->next = *head_ref;
        *head_ref = new_node;
    } else {
        struct Node* current = *head_ref;
        while (current->next != NULL && current->next->data < data) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

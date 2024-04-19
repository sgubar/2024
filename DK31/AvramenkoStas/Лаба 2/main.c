#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

// Функція для вставки елемента перед максимальним
void insertBeforeMax(struct Node** head_ref, int data) {
    struct Node* new_node = newNode(data);

    // Якщо список порожній або вставлений елемент менший за перший елемент
    if (*head_ref == NULL || data <= (*head_ref)->data) {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }

    // Якщо вставлений елемент менший за наступні елементи у списку
    struct Node* current = *head_ref;
    struct Node* maxNode = *head_ref;
    while (current->next != NULL) {
        if (current->next->data > maxNode->data)
            maxNode = current->next;
        current = current->next;
    }

    new_node->next = maxNode->next;
    maxNode->next = new_node;
}

int main() {
    struct Node* head = NULL;
    int num;

    printf("Введіть цифру (для завершення введіть -1): ");
    while (scanf("%d", &num) == 1 && num != -1) {
        insertBeforeMax(&head, num);
        printf("Введіть наступну цифру (для завершення введіть -1): ");
    }

    // Виведення списку
    printf("Linked List: ");
    printList(head);

    return 0;
}


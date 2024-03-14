#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

// Реалізація функцій для роботи зі списком

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Виділення пам'яті під новий вузол
    if (newNode == NULL) {
        printf("Помилка при виділенні пам'яті для нового вузла.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* createList() {
    return NULL; // Початково список порожній, тому повертаємо NULL
}

void append(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode; // Якщо список порожній, то новий вузол стає головою списку
        return;
    }
    struct Node* current = *headRef;
    while (current->next != NULL) {
        current = current->next; // Перехід до кінця списку
    }
    current->next = newNode; // Додавання нового вузла в кінець списку
}




#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

// Функція створення нового вузла з заданими даними
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Функція додавання нового елемента до списку
void add_element(Node** head, int data) {
    Node* new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Функція видалення елемента зі списку
void remove_element(Node** head, int data) {
    Node* current = *head;
    Node* prev = NULL;
    if (current != NULL && current->data == data) {
        *head = current->next;
        free(current);
        return;
    }
    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) return;
    prev->next = current->next;
    free(current);
}

// Функція вставки елемента за заданим індексом
void insert_element(Node** head, int index, int data) {
    if (index < 0) return;
    Node* new_node = create_node(data);
    if (index == 0) {
        new_node->next = *head;
        *head = new_node;
        return;
    }
    Node* current = *head;
    for (int i = 0; current != NULL && i < index - 1; i++) {
        current = current->next;
    }
    if (current == NULL) return;
    new_node->next = current->next;
    current->next = new_node;
}

// Функція видалення всього списку
void delete_list(Node** head) {
    Node* current = *head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

// Функція отримання розміру списку
int size(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Функція виведення списку на екран
void display(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}


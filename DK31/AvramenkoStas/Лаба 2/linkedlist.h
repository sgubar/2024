#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// Структура для вузла списку
struct Node {
    int data;
    struct Node* next;
};

// Прототипи функцій
struct Node* newNode(int data);
void printList(struct Node* head);
void insertSorted(struct Node** head_ref, int data);

#endif


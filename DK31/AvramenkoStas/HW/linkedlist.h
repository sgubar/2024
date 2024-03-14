#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// Оголошення структури та прототипів функцій для роботи зі списком

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data);
struct Node* createList();
void append(struct Node** headRef, int data);
void deleteNode(struct Node** headRef, int key);
void insertAtIndex(struct Node** headRef, int index, int data);
void deleteList(struct Node** headRef);
int getSize(struct Node* head);
void printList(struct Node* head);

#endif


#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "ListNode.h"

struct LinkedList {
    struct ListNode* head;
};

struct LinkedList* createList();
void addNode(struct LinkedList* list, int data);
void deleteNode(struct LinkedList* list, int data);
void insertNode(struct LinkedList* list, int data, int index);
void deleteList(struct LinkedList* list);
int getListSize(struct LinkedList* list);
void printList(struct LinkedList* list);

#endif /* LINKEDLIST_H */

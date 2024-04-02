#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

struct LinkedList* createList() {
    struct LinkedList* newList = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    if (newList == NULL) {
        printf("Не вдалося виділити пам'ять для списку.\n");
        return NULL;
    }
    newList->head = NULL;
    return newList;
}

void addNode(struct LinkedList* list, int data) {
    struct ListNode* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        struct ListNode* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}



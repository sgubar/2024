#include <stdio.h>
#include <stdlib.h>
#include "ListNode.h"

struct ListNode* createNode(int data) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (newNode == NULL) {
        printf("Не вдалося виділити пам'ять для вузла.\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void freeNode(struct ListNode* node) {
    free(node);
}

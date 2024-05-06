#include "list.h"
#include "point.h"

#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>

List *createList(void) {
    List *result = (List *) malloc(sizeof(List));

    // if List pointer not null setup initial constants
    if (result != NULL) {
        result->count = 0;
        result->head = NULL;
        result->tail = NULL;
    }

    return result;
}



void destroyList(List *list) {
    if (list == NULL) {
        return ;
    }

    ListNode *node = list->head;
    ListNode *next = NULL;

    // destroy every node
    while (NULL != node) {
        next = node->next;

        destroyTrapezium(node->tr);
        free(node);

        node = next;
    }

    free(list);
}



void appendTrapeziumToList(List *list, Trapezium *tr) {
    if (list == NULL) {
        return;
    }

    ListNode *node = (ListNode *) malloc(sizeof(ListNode));
    if (node == NULL) {
        return;
    }

    Trapezium *tempTr = createTrapeziumFromCords(tr->A->x, tr->A->y, tr->B->x, tr->B->y,
                                                 tr->C->x, tr->C->y, tr->D->x, tr->D->y, tr->color);
    node->tr = tempTr;
    node->next = NULL;

    if (list->head == NULL) {
        // if list empty
        list->head = list->tail = node;
        node->prev = NULL;
    } else {
        // if list not empty
        node->prev = list->tail;
        list->tail->next = node;
        list->tail = node;
    }

    list->count++;
}



void deleteTrapeziumFromList(List *list, unsigned int index) {
    ListNode *previous, *current = list->head;
    unsigned int i = 0;

    // if head element
    if (index == 0) {
        list->head = current->next;
        list->head->prev = NULL;
        list->count--;

        destroyTrapezium(current->tr);
        free(current);

        return;
    }

    // cycle through list until index
    while (current != NULL && i != index) {
        previous = current;
        current = current->next;
        i++;
    }

    previous->next = current->next;
    current->next = previous;
    destroyTrapezium(current->tr);
    free(current);

    if ((index + 1) == list->count) {
        // if last element deleted -> set new tail
        list->tail = previous;
    }

    list->count--;
}


void drawTrapeziumsList(List *trs) {
    if (NULL == trs) {
        return;
    }

    ListNode *curr = trs->head;
    while (curr != NULL) {
        drawTrapezium(curr->tr);
        curr = curr->next;
    }
}

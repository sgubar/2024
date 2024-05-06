#ifndef LIST_H
#define LIST_H

#include "trapezium.h"

typedef struct listNodeTag {
    Trapezium *tr;
    struct listNodeTag *next;
    struct listNodeTag *prev;
} ListNode;


typedef struct listTag {
    ListNode *head;
    ListNode *tail;
    unsigned int count;
} List;



List *createList(void);
void destroyList(List *list);
void appendTrapeziumToList(List *list, Trapezium *tr);
void deleteTrapeziumFromList(List *list, unsigned int index);
void drawTrapeziumsList(List *trs);

#endif

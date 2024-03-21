#ifndef LIST_H
#define LIST_H

typedef struct listNodeTag {
    double number;
    struct listNodeTag *next;
} ListNode;

typedef struct listTag {
    ListNode *head;
    ListNode *tail;
    unsigned int count;
} List;

List *createList(void);
void destroyList(List *list);

void insertNumberToList(List *list, unsigned int index, double number);
void appendNumberToList(List *list, double number);
void deleteNumberFromList(List *list, unsigned int index);

void printList(List *list);
unsigned int listSize(List *list);

#endif

//
// Created by Nazar Pechkovsky on 02.04.2024.
//

#ifndef LIST_H
#define LIST_H

typedef struct ElementInList {
    struct ElementInList *next;
    int value;
} ElementInList;

typedef struct {
    ElementInList *head;
} StartOfList;

void checkAllocation(void *a);
StartOfList *CreateFirstElementInList(void);
void AddElementInList(StartOfList *list, int value);
int InputInt();
void DeleteList(StartOfList *list);
void DeleteFirstElementLessThanAverage(StartOfList *list);
void PrintList(StartOfList *list);
double CountAverage(StartOfList *list);
void clearInputBuffer();

#endif // LIST_H

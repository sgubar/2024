#ifndef list_h
#define list_h

#include <stdio.h>

typedef struct listElement {
  int data;
  struct listElement *next;
} listElement;

typedef struct tagList { //структура для списку
listElement *head; 
int data;  //початок (голова) списку
} List; //назва структури

listElement *create_listElement(int data);
listElement delete_listElement(listElement *head, int data);
List *createList(void);
void destroyList(List *list);

void add_to_end(listElement **head, int data);
void print_forward(listElement *head);
void print_backward(listElement *head);

#endif

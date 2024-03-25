#ifndef list_h
#define list_h

#include <stdio.h>

typedef struct listElement {
  int data; //значення елемента списку
  struct listElement *next; //вказівник на наступний елемент
} listElement; //структура елемента списку

typedef struct tagList { //структура для списку
listElement *head; //початок списку
int data;  //значення елементів
} List; //структура списку

listElement *create_listElement(int data); //створення нового елемента списку
void delete_listElement(listElement *head, int data); //видалення елемента списку
List *createList(void); //створення списку
void destroyList(List *list); //видалення списку

void add_to_end(listElement **head, int data); //додавання елементу в кінець списку
void print_forward(listElement *head); //виведення елементів списку в прямому порядку
void print_backward(listElement *head); //виведення елементів списку в зворотньому порядку

#endif

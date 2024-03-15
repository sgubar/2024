
#ifndef list_double_h
#define list_double_h

#include <stdio.h>

typedef struct tagNodeDoubl { // нода списку
  double doubl;
  struct tagNodeDoubl *next;
} NodeDoubl;

typedef struct tagListDouble {// створення списку 
  NodeDoubl *head;
  NodeDoubl *tail;
  int count;
} ListDoubl;

ListDoubl *createListRepeatDoubl();// функція створення списку

ListDoubl *fillListDoubl();//функція заповнення списку користувачем

void deleteEvryThirdElementInList(ListDoubl *list);//функція видалення кожного третього елемента, поки не залишиться менше трьох

int addListDoubl(ListDoubl *list, double doubl);// функція додавання елементу в кінець списку

void destroyListDoubl(ListDoubl *list);//функція видалення списку

void printListDoubl(ListDoubl *list);//функція виводу елементів списку

#endif 
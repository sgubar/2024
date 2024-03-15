
#ifndef list_double_h
#define list_double_h

#include <stdio.h>



typedef struct tagNodeDoubl { // нода списку
  double *doubl;
  struct tagNodeDoubl *next;
} NodeDoubl;

typedef struct tagListDouble {// створення списку 
  NodeDoubl *head;
  NodeDoubl *tail;

  int count;
} ListDoubl;

ListDoubl *createListDoubl();// функція створення списку

int addListDoubl(ListDoubl *list, double *doubl);// функція додавання елементу в кінець списку

void destroyDoubleInLIst(ListDoubl *list,  unsigned int index);//функція видалення елементу зі списку за індексом

int addListDoublAt(ListDoubl *list, double *doubl,  unsigned int index);// функція додавання елементу в список за індексом
 
void destroyListDoubl(ListDoubl *list);//функція видалення списку

int countListDoubl(ListDoubl *list);//функція підрахунку кількості елементів у списку

void destroyFirstDoubleInLIst(ListDoubl *list);//функція видалення першого елементу зі списку 

void destroyLastDoubleInLIst(ListDoubl *list);//функція видалення першого елементу зі списку 

void printListDoubl(ListDoubl *list);//функція виводу елементів списку

#endif 
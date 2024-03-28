#ifndef doptwolist_h
#define doptwolist_h

#include <stdio.h>

typedef struct tagDouble2ListElement Double2ListElement;
struct tagDouble2ListElement {
  int value;
  Double2ListElement *prev;
  Double2ListElement *next;
};

Double2ListElement *createDouble2ListElement(double value);
void deleteDouble2ListElement(Double2ListElement *element);
void printDouble2ListElement(Double2ListElement *element);

// Double2List

typedef struct tagDouble2List {
  Double2ListElement *head;
  Double2ListElement *tail;
} Double2List;

Double2List *createDouble2List(void);
void deleteDouble2List(Double2List *list);

void printDouble2List(Double2List *list);

long countOfDouble2List(Double2List *list);
// 1: success, 0 - fail
int addDoubleValueToDouble2List(Double2List *list, double value);
void removeLastElementFromDouble2List(Double2List *list);
void removeFirstElementFromDouble2List(Double2List *list);

// 1: success, 0 - fail
int insertDoubleElementToDouble2ListAtIndex(Double2List *list, int index, double value);
// 1: success, 0 - fail
int removeDoubleElementFromDouble2ListAtIndex(Double2List *list, int index);

// double every element in list
void doubleElement(Double2List *list, double element);

#endif 

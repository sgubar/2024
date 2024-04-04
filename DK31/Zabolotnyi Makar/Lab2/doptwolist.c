#include "doptwolist.h"
#include <stdlib.h>
#include <string.h>

// Функція створення елементу списку
Double2ListElement *createDouble2ListElement(double value) {
  Double2ListElement *result = (Double2ListElement *)malloc(sizeof(Double2ListElement));

  if (NULL != result) {
    bzero(result, sizeof(Double2ListElement));
    result->value = value;
    result->next = NULL;
    result->prev = NULL;
  }

  return result;
}


// Функція видалення елементу списку
void deleteDouble2ListElement(Double2ListElement *element) {
  if (NULL != element) {
    free(element);
  }
}

// Функція виведення елементу списку
void printDouble2ListElement(Double2ListElement *element) {
  if (NULL != element) {
    printf("%d", element->value);
  }
}

// Функція створення списку

Double2List *createDouble2List(void) {
  Double2List *result = (Double2List *)malloc(sizeof(Double2List));

  if (NULL != result) {
    memset(result, 0, sizeof(Double2List));
  }

  return result;
}
// Функція видалення списку
void deleteDouble2List(Double2List *list) {
  if (NULL == list) {
    return ;
  }

  Double2ListElement *element = list->head;
  // Якщо список не порожній
  while(NULL != element) {
    Double2ListElement *tmp = element->next;
    deleteDouble2ListElement(element);
    element = tmp;
  }

  free(list);
}
// Функція виведення списку
void printDouble2List(Double2List *list) {

  if (NULL == list) {
    printf("Invalid a pointer to the list\n");
    return;
  }

  printf("[");

    Double2ListElement *element = NULL;
  for (element = list->head; element != list->tail; element = element->next) {
    printDouble2ListElement(element);
    printf(",");
  }

  if (element != NULL) {
    printDouble2ListElement(element);
  }

  printf("]\n");
}
// Функція повертає кількість елементів у складі списку
long countOfDouble2List(Double2List *list) {
  if (NULL == list) {
    return 0;
  }

  long count = 0;

  for (Double2ListElement *element = list->head; element != NULL; element = element->next, count ++);

  return count;
}
// Функція додавання елементу до списку
int addDoubleValueToDouble2List(Double2List *list, double value) {
  if (NULL == list || (list->head == NULL && list->head != list->tail)) {
    return 0;
  }

  Double2ListElement *element = createDouble2ListElement(value);
  if (NULL == element) {
    return 0;
  }

  if (NULL == list->head) {
    list->head = element;
    list->tail = list->head;
    return 1;
  }

  list->tail->next = element;
  element->prev = list->tail;
  list->tail = element;

  return 1;
}

void removeLastElementFromDouble2List(Double2List *list) {
  if (NULL == list || (list->head == NULL && list->head != list->tail)) {
    return;
  }

  if (NULL == list->head) {
    return;
  }

  // is single element list?
  if (list->head == list->tail) {
    deleteDouble2ListElement(list->head);
    list->head = NULL;
    list->tail = NULL;
    return;
  }

  Double2ListElement *toDelete = list->tail;
  list->tail = toDelete->prev;
  list->tail->next = NULL;

  deleteDouble2ListElement(toDelete);
}

void removeFirstElementFromDouble2List(Double2List *list) {
  if (NULL == list || (list->head == NULL && list->head != list->tail)) {
    return;
  }

  if (NULL == list->head) {
    return;
  }

  if (list->head == list->tail) {
    deleteDouble2ListElement(list->head);
    list->head = list->tail = NULL;
    return;
  }

  Double2ListElement *toDelete = list->head;
  list->head = toDelete->next;
  list->head->prev = NULL;

  deleteDouble2ListElement(toDelete);
}
// Функція додавання елементу до списку по індексу
int insertDoubleElementToDouble2ListAtIndex(Double2List *list, int index, double value) {

  if (NULL == list || (list->head == NULL && list->head != list->tail)) {
    return 0;
  }

  long count = countOfDouble2List(list);

  if (count == index) {
    return addDoubleValueToDouble2List(list, value);
  } else if (index > count) {
    return 0;
  }

  Double2ListElement *element = createDouble2ListElement(value);
  if (NULL == element) {
    return 0;
  }

  if (0 == index) {
    element->next = list->head;
    list->head->prev = element;
    list->head = element;
  } else {
    int current = 0;
    Double2ListElement *ex_element = list->head;
    for (; ex_element != NULL && current != index; ex_element = ex_element->next, current ++);

    element->next = ex_element;
    element->prev = ex_element->prev;
    ex_element->prev = element;
    element->prev->next = element;
  }

  return 1;
}
// Функція видалення елементу зі списку по індексу
int removeDoubleElementFromDouble2ListAtIndex(Double2List *list, int index) {
  if (NULL == list || (list->head == NULL && list->head != list->tail)) {
    return 0;
  }

  long count = countOfDouble2List(list);
  if (index >= count) {
    return 0;
  }

  if (0 == index) {
    removeFirstElementFromDouble2List(list);
    return 1;
  } else if (index == (count - 1)) {
    removeLastElementFromDouble2List(list);
    return 1;
  } else {
    int current = 0;
    Double2ListElement *ex_element = list->head;
    for (; ex_element != NULL && current != index; ex_element = ex_element->next, current ++);

    ex_element->prev->next = ex_element->next;
    ex_element->next->prev = ex_element->prev;

    deleteDouble2ListElement(ex_element);
  }

  return 1;
}

// Функція для подвоєння кожного входження заданого елемента
void doubleElement(Double2List *list, double element) {
  if (NULL == list || (list->head == NULL && list->head != list->tail)) {
    return;
  }
  
  Double2ListElement *current = list->head;
  while (current != NULL) {
      if (current->value == element){
          Double2ListElement *duplicate = createDouble2ListElement(element);
          duplicate->next = current->next;
          duplicate->prev = current;
          current->next = duplicate;
          if(current == list->tail){
              list->tail = duplicate;
          }
        //current->next = duplicate;
            current = duplicate->next;
        }
      else {
        current = current->next;    
      } 
  } 
}

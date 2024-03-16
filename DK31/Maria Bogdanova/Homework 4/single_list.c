#include "single_list.h"
#include <stdio.h>
#include <stdlib.h>

SingleListFloatElement *createSingleListFloatElement(float value) {
  SingleListFloatElement *result =
      (SingleListFloatElement *)malloc(sizeof(SingleListFloatElement));
  if (NULL != result) {
    result->value = value;
    result->next = NULL;
  }
  return result;
}

void deleteSingleListFloatElement(SingleListFloatElement *element) {
  if (NULL != element) {
    free(element);
  }
}
void printSingleListFloatElement(SingleListFloatElement *element) {
  if (NULL != element) {
    printf("%f", element->value);
  }
}

FloatSingleList *createFloatSingleList(void) {
  FloatSingleList *result = (FloatSingleList *)malloc(sizeof(FloatSingleList));

  if (NULL != result) {
    result->head = NULL;
  }
  return result;
}

void deleteFloatSingleList(FloatSingleList *list) {
  if (NULL == list) {
    return;
  }
  SingleListFloatElement *element = list->head;
  while (NULL != element) {
    SingleListFloatElement *nn = element->next;
    free(element);
    element = nn;
  }
  free(list);
}

void printFloatSingleList(FloatSingleList *list) {
  if (NULL == list) {
    printf("Invalid pointer to the list\n");
    return;
  }
  if (NULL == list->head) {
    printf("The list is empty  \n");
  }
  printf("[");
  /*SingleListFloatElement *element =list->head;
  while (NULL!=element){
    SingleListFloatElement *nn=element->next;
    printSingleListFloatElement(element);
    element=nn;
  }*/
  for (SingleListFloatElement *element = list->head; element != NULL;
       element = element->next) {
    printSingleListFloatElement(element);
         if (element->next!=NULL){
            printf(", ");
         }
  }
  printf("]\n");
}

long countOfFloatSingleList(FloatSingleList *list) {
  if (NULL == list) {
    return 0;
  }
  long count = 0;
  /* SingleListFloatElement *element =list->head;

   while (NULL!=element){
     SingleListFloatElement *nn=element->next;
     printSingleListFloatElement(element);
     element=nn;
   }*/
  for (SingleListFloatElement *element = list->head; element != NULL;
       element = element->next, count++)
    ;

  return count;
}
float addFloatValueToFloatSingleList(FloatSingleList *list,
                                                       float value) {
  if (NULL == list) {
    return 0;
  }
  SingleListFloatElement *element = createSingleListFloatElement(value);
  if (NULL == element) {
    return 0;
  }
  if (NULL == list->head) {
    list->head = element;
    return 1;
  }

  SingleListFloatElement *tail = list->head;

  while (NULL != tail) {
    tail = tail->next;
  }
  tail->next = element;
  return 1;
}
void removeLastElementFromFloatSingleList(FloatSingleList *list) {
  if (NULL == list) {
    return;
  }
  if (NULL == list->head) {
    return;
  }
  SingleListFloatElement *element = list->head;
  if (NULL == element->next) {
    list->head = NULL;
    deleteSingleListFloatElement(element);
    return;
  }
  while (NULL != element->next &&
         NULL !=
             element->next
                 ->next) { //якщо поточний елемент має наступний елемент, то ми
                           //на нього перекидаємось. коли наступний елемент буде
                           //останнім, то ми записуємо в нього NULL
    element = element->next;
  }
  deleteSingleListFloatElement(element->next);
  element->next = NULL;
}
void removeFirstElementFromFloatSingleList(FloatSingleList *list) {
  if (NULL == list) {
    return;
  }
  if (NULL == list->head) {
    return;
  }
  SingleListFloatElement *element = list->head->next;
  deleteSingleListFloatElement(list->head);
  list->head = element;
}

float 
insertFloatElementToFloatSingleListAtIndex(FloatSingleList *list, float index,
                                           float value) {
  if (NULL == list) {
    return 0;
  }
  long count = countOfFloatSingleList(list);
  if (count == index) {
    return addFloatValueToFloatSingleList(list, value);
  }
  SingleListFloatElement *element = createSingleListFloatElement(value);
  if (NULL == element) {
    return 0;
  }
  if (0 == index) {
    element->next = list->head;
    list->head = element;
  } else {
    float current = 0;
    SingleListFloatElement *ex_element = list->head;
    for (; ex_element != NULL && current <= index - 1;
      ex_element = ex_element->next, current++);
    
      element->next = ex_element->next;
      ex_element->next= element;
  }
  
  return 1;
  
}
float removeFloatElementFromFloatSingleListAtIndex(FloatSingleList *list, float index) {
  if (NULL == list) {
    return 0;
  } long count = countOfFloatSingleList(list);
  if (index >=count){
    return 0;
  }
if(0 == index){
  removeFirstElementFromFloatSingleList(list);
  return 1;
} else if (index==(count-1)){
  removeLastElementFromFloatSingleList(list);
  return 1;
} else {
  float current = 0;
  SingleListFloatElement *ex_element = list->head;
  for (; ex_element != NULL && current <= index - 1;
    ex_element = ex_element->next, current++);
  SingleListFloatElement *to_delete = ex_element->next;
  ex_element->next = to_delete->next;
  deleteSingleListFloatElement(to_delete);
}

  
  return 1;
}

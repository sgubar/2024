#include <stdio.h>
#include "list.h"

listElement *create_listElement(int data) {
  listElement *new_listElement = (listElement *)malloc(sizeof(listElement));
  new_listElement->data = data;
  new_listElement->next = NULL;
  return new_listElement;
}
listElement delete_listElement(listElement *head, int data){
  listElement *current = head;
  listElement *prev = NULL;
  while (current != NULL && current->data != data){
    prev = current;
    current = current->next;
  }
  if (current == NULL){
    return *head;
  }
  if (prev == NULL){
    head = current->next;
    
  }else{
    prev->next = current->next;    
  }
  free(current);
  return *head;
  
}

List *createList(void){      // функція створення списку
  List *result = (List *)malloc(sizeof(List)); //виділяємо пам'ять для списку

     if (NULL != result) { //якщо виділилась пам'ять
       result->head = NULL; //початок списку поки NULL
  }
         return result;
}

void destroyList(List *list) { //видаляємо список
    if (NULL == list) { //якщо список не існує
       return; //виходимо з функції
  } //наш список зберігає не лише вказівники, а й елементи
        listElement *element = list->head; //елемент початку списку
         while (NULL != element) {    //ітеруємося до тих пір, доки while не дорінюватиме 0
           listElement *nn = element->next; //потрібни видалити один елемент і перейти до наступного
    free(element);//вивільнення пам'яті елементу
    element = nn; //присвоюємо елементу nn
  }
  free(list); //вивільнення пам'яті списку
}

void add_to_end(listElement **head, int data){
  listElement *new_listElement = create_listElement(data);
  if (*head == NULL) {
    *head = new_listElement;
  } else {
    listElement *temp = *head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = new_listElement;
  }
}
void print_forward(listElement *head){
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}
void print_backward(listElement *head){
  if (head == NULL) {
    return;
  }
  print_backward(head->next);
  printf("%d ", head->data);
  
}

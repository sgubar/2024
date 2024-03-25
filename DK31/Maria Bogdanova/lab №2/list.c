#include <stdio.h>
#include <stdlib.h>
#include "list.h"

listElement *create_listElement(int data) {//створення нового елемента списку
  listElement *new_listElement = (listElement *)malloc(sizeof(listElement)); //виділення пам'яті для нового елемента списку
  new_listElement->data = data; // присвоює значення data для data нового елемента списку
  new_listElement->next = NULL; //значення NULL члену next нового елемента списку. Це означає, що новий елемент списку буде останнім елементом списку
  return new_listElement;
}

List *createList(void){      // функція створення списку
  List *result = (List *)malloc(sizeof(List)); //виділяємо пам'ять для списку

     if (NULL != result) { //якщо виділилась пам'ять
       result->head = NULL; //початок списку поки NULL
  }
         return result;
}

void destroyList(List *list) { //видалення списку
    if (NULL == list) { //якщо список не існує
       return; //виходимо з функції
  } 
        listElement *element = list->head; //елемент початку списку
         while (NULL != element) {    //ітеруємося до тих пір, доки while не дорінюватиме 0
           listElement *nn = element->next; //потрібно видалити один елемент і перейти до наступного
    free(element);//вивільнення пам'яті елементу
    element = nn; //присвоюємо елементу nn
  }
  free(list); //вивільнення пам'яті списку
}

void add_to_end(listElement **head, int data){ //функція додавання елемента в кінець списку
  listElement *new_listElement = create_listElement(data); //створюємо новий елемент списку
  if (*head == NULL) { //якщо список пустий
    *head = new_listElement; //початок списку стає новм елементом
  } else {
    listElement *temp = *head;///Якщо список не пустий, нам потрібно знайти його кінець. Для цього ми використовуємо temp, який спочатку ініціалізується значенням *head 
    while (temp->next != NULL) {//Потім ми використовуємо цикл while, щоб переміщатися по списку, доки не знайдемо елемент, наступний за яким (temp->next) є NULL.
      temp = temp->next;
    }
    temp->next = new_listElement; //Коли ми знайдемо кінець списку, ми можемо додати новий елемент, встановивши temp->next на new_listElement.
  }
}
void print_forward(listElement *head){
  while (head != NULL) {//цикл while використовується для перебору всіх елементів списку. Цикл буде повторюватися, доки не буде досягнуто кінця списку (head == NULL).
    printf("%d ", head->data); //Цей рядок коду друкує значення data поточного елемента списку
    head = head->next; //Цей рядок коду переміщує вказівник head на наступний елемент списку
  }
  printf("\n");
}
void print_backward(listElement *head){
  if (head == NULL) { //якщо список порожній
    return; //повертаємось
  } 
   
  print_backward(head->next); //
  printf("%d ", head->data); 
  
  //Приклад: (для 3-х елементів) 
  //Виклик функції наступного (другого) елемента після head 
  //Друкується значення data для третього елемента.
  //Функція повертається.
  //Функція друкує значення data для другого елемента.
  //Функція повертається
  //Функція друкує значення data для першого елемента.
  //Функція повертається

}

#include "single_list.h"
 #include <stdio.h>
#include <stdlib.h>

SingleListFloatElement *createSingleListFloatElement(float value) //створюємо елемент
{ 
  SingleListFloatElement *result = (SingleListFloatElement *)malloc(sizeof(SingleListFloatElement)); //виділяємо пам'ять для елементу
  if (NULL != result) { //якщо виділилась пам'ять 
    result->value = value; //записуємо значення 
    result->next = NULL; //поки елементу немає ні в одному зі списків, ми нікуди не посилаємось
  }
  return result; 
}

void deleteSingleListFloatElement(SingleListFloatElement *element) { //видалення елементу
  if (NULL != element) { //якщо елеент існує
    free(element); //звільняємо пам'ять
  }
}
void printSingleListFloatElement(SingleListFloatElement *element) { //вивід елементу
  if (NULL != element) { //якщо елемент існує
    printf("%f", element->value); //виводимо значення елемента value
  }
}

FloatSingleList *createFloatSingleList(void) { //створюємо список
  FloatSingleList *result = (FloatSingleList *)malloc(sizeof(FloatSingleList)); //виділяємо пам'ять для списку

  if (NULL != result) { //якщо виділилась пам'ять
    result->head = NULL; //початок списку поки NULL
  }
  return result;
}

void deleteFloatSingleList(FloatSingleList *list) { //видаляємо список
  if (NULL == list) { //якщо список не існує
    return; //виходимо з функції
  } //наш список зберігає не лише вказівники, а й елементи
  SingleListFloatElement *element = list->head; //елемент початку списку
  while (NULL != element) {    //ітеруємося до тих пір, доки while не дорінюватиме 0
    SingleListFloatElement *nn = element->next; //потрібни видалити один елемент і перейти до наступного
    free(element);//вивільнення пам'яті елементу
    element = nn; //присвоюємо елементу nn
  }
  free(list); //вивільнення пам'яті списку
}

void printFloatSingleList(FloatSingleList *list) { //вивід списку
  if (NULL == list) { //якщо список не існує
    printf("Invalid pointer to the list\n"); //виводимо повідомлення про помилку
    return;
  }
  printf("[");
  /*SingleListFloatElement *element =list->head;
  while (NULL!=element){
    SingleListFloatElement *nn=element->next;
    printSingleListFloatElement(element);
    element=nn;
  }*/
  for (SingleListFloatElement *element = list->head; element != NULL; element = element->next) { //проходимося по всім елементам 
    printSingleListFloatElement(element); //виводимо значення елементу
         if (element->next!=NULL){ //якщо наступний елемент існує
            printf(","); //виводимо 
         }
  }
  printf("]\n");
}

long countOfFloatSingleList(FloatSingleList *list) { //підрахунок кількості елементів
  if (NULL == list) { //якщо список не існує - повертаємо нуль
    return 0;
  }
  long count = 0; //початкове значення кількості елементів
  /* SingleListFloatElement *element =list->head;

   while (NULL!=element){
     SingleListFloatElement *nn=element->next;
     printSingleListFloatElement(element);
     element=nn;
   }*/
  for (SingleListFloatElement *element = list->head; element != NULL; //проходимося по всім елементам, щоб їх порахувати 
       element = element->next, count++); //збільшуємо нумерацію елементів на 1

  return count; //повертаємо кількість елементів
}
float addFloatValueToFloatSingleList(FloatSingleList *list, float value) { //додавання елементу до списку
  if (NULL == list) { //якщо список не існує
    return 0;//повертаємо 0
  }
  SingleListFloatElement *element = createSingleListFloatElement(value); //створюємо елемент
  if (NULL == element) { //якщо елемент не існує
    return 0; //повертаємо 0
  }
  if (NULL == list->head) { //перевірка чи список не пустий
    list->head = element; //початок списку стає елементом
    return 1; //повертаємо 1
  }
  
  //якщо наш список не пустий, то нам потрібно проітеруватися до кінця списку. Поки next !=0

  SingleListFloatElement *tail = list->head;

  while (NULL != tail) { //поки не дійдемо до кінця списку
    tail = tail->next; //переходимо до наступного елементу, 
    //якщо у нас є 1 елемент списку, то next=0, тому tail буде дивитися на останній елемент
  }
  tail->next = element; //наступний елемент списку є кінцем
  return 1;
}
void removeLastElementFromFloatSingleList(FloatSingleList *list) { //видалення останнього елементу
  if (NULL == list) { //якщо список не існує
    return; //повертаємось
  }
  if (NULL == list->head) { //якщо пустий початок списку
    return; //повертаємось
  }
  SingleListFloatElement *element = list->head; //елемент початку списку 
  if (NULL == element->next) { //якщо наступний елемент списку не існує
    list->head = NULL; //початок = NULL
    deleteSingleListFloatElement(element); //видаляємо елемент
    return; //повертаємось
  }
  while (NULL != element->next && NULL !=element->next->next) {
    element = element->next;
  }
  deleteSingleListFloatElement(element->next);
  element->next = NULL;
} //якщо поточний елемент має наступний елемент, то ми на нього перекидаємось. коли наступний елемент буде останнім, то ми записуємо в нього NULL
void removeFirstElementFromFloatSingleList(FloatSingleList *list) { //видаження першого елементу списку
  if (NULL == list) {
    return;
  }
  if (NULL == list->head) {
    return;
  }
  SingleListFloatElement *element = list->head->next; //поточний елемент = натупний елемент
  deleteSingleListFloatElement(list->head); //видаляємо head списку
  list->head = element; //початок списку = поточний елемент
}

float insertFloatElementToFloatSingleListAtIndex(FloatSingleList *list, float index, float value) //додавання елементу за індексом
{
  if (NULL == list) { //перевіряємо чи валідний наш список
    return 0;
  }
  long count = countOfFloatSingleList(list); //підраховуємо кількість елементів
  if (count == index) //якщо індекс=кількості елементів
  { 
    return addFloatValueToFloatSingleList(list, value); //додаємо елемент в кінець списку
  }
  SingleListFloatElement *element = createSingleListFloatElement(value);  //створюємо елемент
  if (NULL == element) { 
    return 0;
  }
  if (0 == index) //якщо індекс = 0
  {
    element->next = list->head; //наступний елемент = початок списку
    list->head = element; //початок=елемент
  } else {
    float current = 0; //маємо початкове значення індексу =0
    SingleListFloatElement *ex_element = list->head; //ex_element - елемент, який ми будемо перевіряти (для початку списку)
    for (; ex_element != NULL && current <= index - 1; ex_element = ex_element->next, current++); //проходимося по всім елементам, поки не дійдемо до індексу -1 
    
      element->next = ex_element->next; 
      ex_element->next= element;
  }
  
  return 1;
  
}
float removeFloatElementFromFloatSingleListAtIndex(FloatSingleList *list, float index) { //видалення елементу за індексом
  if (NULL == list) {
    return 0;
  } long count = countOfFloatSingleList(list); //підраховуємо кількість елементів
  if (index >=count){ //якщо індекс більший за кількість елементів 
    return 0;//повертаємо 0
  }
if(0 == index){ //якщо індекс=0
  removeFirstElementFromFloatSingleList(list); //видаляємо перший елемент
  return 1;
} else if (index==(count-1)){ //якщо індекс = (кількість елементів -1)
  removeLastElementFromFloatSingleList(list);//видаляємо останній елемент
  return 1;
} else {
  float current = 0; //початкове значення індексу =0
  SingleListFloatElement *ex_element = list->head; //ex_element - елемент для перевірки = початок списку
  for (; ex_element != NULL && current <= index - 1; ex_element = ex_element->next, current++); //для перевірки індексу ми будемо перевіряти елементи списку, поки не дійдемо до індексу-1
  SingleListFloatElement *to_delete = ex_element->next;//наступний елемент = елемент, який видаляється
  ex_element->next = to_delete->next;
  deleteSingleListFloatElement(to_delete); //видаляємо елемент
}

  
  return 1;
}

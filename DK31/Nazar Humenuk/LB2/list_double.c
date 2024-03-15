#include "list_double.h"
#include <stdlib.h>
#include <cs50.h>
#include <string.h>

ListDoubl *createListRepeatDoubl(){// функція створення списку
    ListDoubl *result = (ListDoubl *)malloc(sizeof(ListDoubl));//виділяємо память для списку

    if (NULL != result) {// якщо не вдалось виділити память
      result->count = 0;// вводимо нульові значення у списку
      result->head = NULL;
      result->tail = result->head;
    }
    return result;//повертаємо список
  
}

ListDoubl *fillListDoubl() {//функція заповнення списку користувачем
    ListDoubl *result = createListRepeatDoubl();// створюємо список
    int kl = 0;// змінна кількості елементів
    printf("Введіть кількість значень, які бажаєте додати в список: ");
    while(scanf("%d", &kl) != 1 || kl < 1) {// отрмуємо кількість елементів від користувача та перевіряємо чи значення є числом та більше 0
        printf("Введено не число або не додатнє значення. Ведіть число : ");
      while (getchar() != '\n');// Очистення буфера введення
    }
    if (result != NULL) {//якщо вдалось виділити память
        double znach = 0;// змінна для значень списку
        for (int i = 0; i < kl; i++) {// цикл для заповнення списку
            printf("Введіть %d число: ", i + 1);
            if (scanf("%lf", &znach) != 1) {// отримуємо значення елемену від користувача та перевіряємо чи воно є числом
                printf("Введено не число. ");
                while (getchar() != '\n'); // Очистення буфера введення
                i--; // Повторити спробу для цього ж числа
            } else {// якщо воно є числом
                addListDoubl(result, znach); // Додати новий елемент
            }
        }
    }
    return result;// повертаємо список
}


int addListDoubl(ListDoubl *list, double doubl){// функція додавання елементу в кінець списку
  int result = 0;

  if (NULL == list) {//якщо списка не існує
    return -1;
  }
  NodeDoubl *node = (NodeDoubl *)malloc(sizeof(NodeDoubl));//виділяємо память для ноди
  if (NULL == node) {//якщо не вдалось виділити память
    return -2;
  }

  node->doubl = doubl;// водимо значення у ноду
  node->next = list->head;// вводимо що наступного значення нема

  if (NULL == list->head) {//якщо першого значення нема
    list->head = list->tail = node;//водимо створену ноду як першу
  } else {//якщо переше значення існує
    list->tail->next = node;// водимо наступне значення для останьо елементу як ноду 
    list->tail = node;//  останій елемент стає нодою
  }

  list->count ++;//збільшуємо значення кількості елементів у спискі

  return result;//виводомо значення , яке означає що помилок не було
}

void destroyListDoubl(ListDoubl *list){//функція видалення списку
  if (NULL == list) {//якщо списка не існує
    return ;
  }

  NodeDoubl *node = list->head;//створюємо вказівник на перший елемент списку
  int i = 0;
  while (i< list->count) {// цикл який перебирає всі елементи списку
    NodeDoubl *next = node->next;// створюємо вказівник на наступний елемент
    free(node);//видаляємо память для елементів
    node = next;// переходимо на наступний елемент списку
    i++;
  }

  free(list);//видаляємо память для списку
}

void deleteEvryThirdElementInList(ListDoubl *list){//функція видалення кожного третього елемента, поки не залишиться менше трьох
  if (NULL == list) {//якщо списка не існує
    return ;
  }
   while (list->count > 2) {//цикл який виконується поки кількість елементів у списку не буде менше трьох
       printListDoubl(list);//виводимо список
     NodeDoubl *nodeD = list->head;// створюємо вказівник на перший елемент списку
     unsigned int i = 1; // змінна збільшення індексу 
     unsigned int k = 0; // змінна кількості видалених елементів
     
     while ( i+k <= list->count-1) {//цикл який перебирає елементи списку до перед останього
       if((i+k+1)%3 == 0){// якщо наступний елемент списку кратний трьом
         NodeDoubl *next = nodeD->next;//створюємо вказівник на елемент кратний трьом
         nodeD->next = next->next;// вводимо наступний елемент списку як наступний елемент для наступного елементу
         free(next);// звільняємо память для елемента кратному трьом
         k++;//збільшуємо клькість видалених елементів
       }
       nodeD = nodeD->next;// переходимо до наступного елементу
       i ++;// збільшуємо індекс
     }
     list->count -= k;//зменшуємо розмір списку на кількість видалених елементів
   }
     
   
}

void printListDoubl(ListDoubl *list){//функція виводу елементів списку
  if (NULL == list) {//якщо список пустий
    return ;
  }
  NodeDoubl *node = list->head;//створюємо вказівник на перший елемент списку
  unsigned int i = 0;
  while (i < list->count) {// цикл виводу елементів списку
    node != list->head ? printf(" -> ") : 0 ;
    printf( "%.2lf", node->doubl);// виводимо
    node = node->next;// переходимо на наступний елемент списку
    i++;
  }
  printf(" \n");
}

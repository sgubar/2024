#include "list_double.h"
#include <stdlib.h>
#include <string.h>

ListDoubl *createListDoubl(){// функція створення списку
    ListDoubl *result = (ListDoubl *)malloc(sizeof(ListDoubl));//виділяємо память для списку

    if (NULL != result) {// якщо не вдалось виділити память
      result->count = 0;// вводимо нульові значення у списку
      result->head = NULL;
      result->tail = NULL;
    }
    return result;//повертаємо список
  
}

int addListDoubl(ListDoubl *list, double *doubl){// функція додавання елементу в кінець списку
  int result = 0;

  if (NULL == list) {//якщо списка не існує
    return -1;
  }
  NodeDoubl *node = (NodeDoubl *)malloc(sizeof(NodeDoubl));//виділяємо память для ноди
  if (NULL == node) {//якщо не вдалось виділити память
    return -2;
  }

  node->doubl = doubl;// водимо значення у ноду
  node->next = NULL;// вводимо що наступного значення нема

  if (NULL == list->head) {//якщо першого значення нема
    list->head = list->tail = node;//водимо створену ноду як першу
  } else {//якщо переше значення існує
    list->tail->next = node;// водимо наступне значення для останьо елементу як ноду 
    list->tail = node;//  останій елемент стає нодою
  }

  list->count ++;//збільшуємо значення кількості елементів у спискі

  return result;//виводомо значення , яке означає що помилок не було
}

void destroyDoubleInLIst(ListDoubl *list, unsigned int index){//функція видалення елементу зі списку за індексом
  if (NULL == list || index > list->count) {// якщо списка не існує та значення ідексу більше ніж є кількість елементів у списку
    return ;
  }
  NodeDoubl *nodeD = list->head;//створюємо вказівник на перший елемент списку
  if (index == 0) { //якщо видаляємо перший елемент
    list->head = list->head->next;// надаємо першому елементу наступний елемент
    free(nodeD);//видяляємо пямять для першого елементу
  }else{
  unsigned int i = 0;
  while ( i != index-1) {// цикл який перебирає елементи до попереднього елементу для індексу
    nodeD = nodeD->next;//перехід на наступний елемент
    i ++;
  }
    NodeDoubl *next = nodeD->next->next;// створюємо вказівник для наступного елементу для елементу за індексом
    free(nodeD->next);//звільняємо память для елементу за індексом
    nodeD->next = next;//вводимо як наступний елемент для попереднього елементу наступний елемент для елементу за індексом
  }
  list->count--;// зменшуємо кількіть елементів у списку
}

int addListDoublAt(ListDoubl *list, double *doubl, unsigned int index){// функція додавання елементу в список за індексом
  int result = 0;

  if (NULL == list || index > list->count) {// якщо списка не існує та значення ідексу більше ніж є кількість елементів у списку
    return -1 ;
  }
  NodeDoubl *node = (NodeDoubl *)malloc(sizeof(NodeDoubl));//виділяємо память для ноди
  if (NULL == node) {//якщо не вдалось виділити память
    return -2;
  }
  node->doubl = doubl;// вводимо значення у ноду
  node->next = NULL;
  if (index == 0) { //якщо вставляємо елемент як перший 
      node->next = list->head;//надаємо для введеної ноди як наступний елемент перший елемент
      list->head = node;// першим елементом стає введена нода
      if (list->tail == NULL) {//якщо список пустий
          list->tail = node;//останій елемент стає введеною нодою
      }
  } else{//якщо вставляємо елемент не як перший
  NodeDoubl *nodeD = list->head;//створюємо вказівник на перший елемент списку
  unsigned int i = 0;
  while (NULL != nodeD && i != index-1) {// цикл який перебирає елементи до попереднього елементу для індексу
    nodeD = nodeD->next;//перехід на наступний елемент
    i ++;
  }
  node->next = nodeD->next;//вказуємо наступний елемент для введеною ножи як натупний елемент для попереднього елементу по ідексу
  nodeD->next = node;//вказуємо настпуний елемент для попереднього елементу по індексу як введену ноду
    if (node->next == NULL) {// якщо введена нода є останнім елементом
        list->tail = node;//останій елемент стає введеною нодою
    }
 }
  list->count ++;//збільшуємо значення кількості елементів у нашому списку
  return result;// виводимо значення , яке означає що помилок не було
}

void destroyListDoubl(ListDoubl *list){//функція видалення списку
  if (NULL == list) {//якщо списка не існує
    return ;
  }

  NodeDoubl *node = list->head;//створюємо вказівник на перший елемент списку

  while (NULL != node) {// цикл який перебирає всі елементи списку
    NodeDoubl *next = node->next;// створюємо вказівник на наступний елемент
    free(node);//видаляємо память для елементів
    node = next;// переходимо на наступний елемент списку
  }

  free(list);//видаляємо память для списку
}

int countListDoubl(ListDoubl *list){//функція підрахунку кількості елементів у списку
  if (NULL == list) {//якщо списка не існує
    return -1;
  }

  return list->count;//виводимо кількість елементів у списку
}

void printListDoubl(ListDoubl *list){//функція виводу елементів списку
  if (NULL == list) {//якщо список пустий
    return ;
  }
  NodeDoubl *node = list->head;//створюємо вказівник на перший елемент списку
  while (NULL != node) {// цикл виводу елементів списку
    printf( "%lf\n", *node->doubl);// виводимо
    node = node->next;// переходимо на наступний елемент списку
  }
}

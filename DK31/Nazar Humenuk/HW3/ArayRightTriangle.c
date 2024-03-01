#include <stdio.h>
#include "ArayRightTriangle.h"
#include "RightTriangle.h"
#include <stdlib.h>
#include <string.h>


void adoptInternalStorage(ArrayRTrgle *a);// функція збільшення памяті масиву в двоє та копіювання попередних даних масиву у нього
int countRTrgleInArray(ArrayRTrgle *a);//функція підрахунку кількості трикітників масиву

ArrayRTrgle *createARTrgle(int preserved){// функція створення структури масиву прямокутних трикутників
  if (preserved <= 0) {// перевірка чи задали розмір більше 0
      return NULL;
    }

  ArrayRTrgle *result = (ArrayRTrgle *)malloc(sizeof(ArrayRTrgle));//виділення памяті для структури масиву трикутників

    if (NULL != result) {//якщо вдалося виділити память
      result->preserved = preserved;//надання розміру масиву
      result->storage = (RTrgle **)malloc(sizeof(RTrgle *) * result->preserved);//виділення памяті для масиву трикутників 
      result->lastElement = 0;// надання нульової кількості елементів у масиві
    }

    return result;// повертаємо структуру масиву трикітників
  }

void destroyARTrgle(ArrayRTrgle *a){//функція знищення структури масиву прямокутних трикутників
  if (NULL == a) {//якщо структури не існує
    return ;
  }

  free(a->storage);// видалити масиву структури
  free(a); // видалити структуру
}


int addRTrgleToArray(ArrayRTrgle *a, RTrgle  *p) {//функція додавання триктників в структуру масиву прямокутних трикутників
  if (NULL == a || NULL == p) {// якщо структури або трикутника не сінує
    return -1 ;
  }

  if (a->lastElement == a->preserved) {//якщо кількість елементів можливих поклати в масив дорівнює нулю

    adoptInternalStorage(a);// збільшуємо память масиву трикутників

    if (a->lastElement == a->preserved) {//якщо не вдалось збільшити память
      return -1;
    }
  }

  a->storage[a->lastElement] = p;//додаємо трикутник у масив
  a->lastElement ++;//збільшуємо кількість трикітників
  return a->lastElement-1;//повертаємо індекс введеного трикутника
}


void adoptInternalStorage(ArrayRTrgle *a) {
  RTrgle **newStorage = (RTrgle **)malloc(sizeof(RTrgle) * a->preserved * 2);// створюємо новий масив трикутників більщий в 2 раза за розмір попереднього

  if (NULL == newStorage) {//якщо не вдалось створити новий масив
    return ;
  }

  memcpy(newStorage, a->storage, sizeof(RTrgle) * a->preserved);// заміняємо дані з попереднього масиву в новий

  free(a->storage);// видаляємо попередній масив
  a->storage = newStorage;// надаємо структурі новий масив
  a->preserved *= 2;//зільшеємо кількість можливих елементів масиву
}


void printARTrgle(ArrayRTrgle *a) {//функція виводу масиву прямокутних трикутників
  if (NULL == a) {//якщо структури не існує
    printf("Invalid reference to the Line");
  }
  
  for (int i = 0; i < countRTrgleInArray(a); i++) {// цикл виводу кожного трикутника структури масиву трикутників
    printRightTriangle(a->storage[i]);//виводимо трикутники
    printf("\n");
  }
}


int replaceRTrgleToArray(ArrayRTrgle *a, RTrgle  *p , int index){// функція заміни елемента масиву  прямокутних трикутників
  if (NULL == a || NULL == p) {//якщо структури або трикутника не існує
    return -1 ;
  }
  if (index < 0 || index >= a->lastElement){//якщо введений індекс не входить в діапазон можливих індексів масиву структури
    return -1 ;
  }
  a->storage[index] = p;// надаємо новий трикутник в масив трикутників з введеним індексом 
  return index;//повертаємо індекс заміненого трикутника в масиві структури
}


  int countRTrgleInArray(ArrayRTrgle *a){
    if (NULL == a) {//якщо структури не існує
      return -1;
    }

    return a->lastElement;//повертаємо кількість елементів у масиві структури
  }


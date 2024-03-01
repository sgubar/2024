#ifndef ArayRightTriangle_h
#define ArayRightTriangle_h

#include <stdio.h>
#include "RightTriangle.h"


typedef struct tagArayRightTriangle{//створюмо структуру масиву тпрямокутних трикутників
  RTrgle **storage;//створюємо масив трикутників
  int preserved;// розмір масиву
  int lastElement;//кількість елементів у масиві
} ArrayRTrgle;// назва виклику створення структури 


ArrayRTrgle *createARTrgle(int preserved);// функція створення масиву прямокутних трикутників

void destroyARTrgle(ArrayRTrgle *a);//функція знищення масиву прямокутних трикутників

int addRTrgleToArray(ArrayRTrgle *a, RTrgle  *p) ;//функція додавання в масив прямокутних трикутників

int replaceRTrgleToArray(ArrayRTrgle *a, RTrgle  *p , int index);// функція заміни елемента масиву  прямокутних трикутників

void printARTrgle(ArrayRTrgle *a) ;//функція виводу масиву прямокутних трикутників



#endif
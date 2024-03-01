#include "RightTriangle.h"
#include "ArayRightTriangle.h"
#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include <cs50.h>
#include <math.h>
#include "dopom.h"

int main(void) {
  
  Point *A = createPoint(0,0);// створюємо точки
  Point *B = createPoint(0,0);
  Point *C = createPoint(0,0);
  zadati_kord(A,B,C); // задаємо кортинати точок
	RTrgle *Triangle = crateRightTrianglePoint(A,B,C);// створюємо трикуткин за точками
  
  zadati_kord(A,B,C); //перезадаємо кординати точок
  RTrgle *Triangle2 = crateRightTriangle(A->x,A->y,B->x,B->y,C->x,C->y);//створюємо трикутниз за допомогою координат
  
  zadati_kord(A,B,C);
  Point *massive = create_massivePoint(A,B,C);// створюємо масив точок
  RTrgle *Triangle3 = crateRightTriangleByMassivePoints(massive);// створюємо трикутник за масивом точок

  ArrayRTrgle *ATR = createARTrgle(2);//створюємо масив прямокутних трикутників з розміром для 2 трикутників
  int a = addRTrgleToArray(ATR,Triangle);// додаємо трикутники в масив
  printf("Індекс доданого трикутника : %d\n", a);// виводимо індекс трикутників у масиві

  a = addRTrgleToArray(ATR,Triangle2);
  printf("Індекс доданого трикутника : %d\n", a);
  
  a = addRTrgleToArray(ATR,Triangle3);
  printf("Індекс доданого трикутника : %d\n", a);

  a = replaceRTrgleToArray(ATR,Triangle3, 0);// замінюємо трикутник з індеком 0 на трикутник 3 в масиві
  
  printf("Масив трикутників :\n");
  printARTrgle(ATR);// виводимо масив трикутників

  destroyARTrgle(ATR);//видаляємо масив трикутників
  destroyRightTriangle(Triangle);//видаляємо трикутник
  destroyRightTriangle(Triangle2);
  destroyRightTriangle(Triangle3);
  destroy_massive(massive);// видаляємо масив точок
  return 0 ;
}
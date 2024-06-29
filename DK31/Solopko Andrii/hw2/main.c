#include "RightTriangle.h"
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
  
  printf("\nТочки 1 трикутника : \n");
  printRightTriangle(Triangle);//виводимо кординати точок трикутника
  printf("Площа 1 трикутника : %f", areaRightTriangle(Triangle));// виводимо площу трикутника
  
  printf("\nТочки 2 трикутника : \n");
  printRightTriangle(Triangle2);
  printf("Площа 2 трикутника : %f", areaRightTriangle(Triangle2));
  
  printf("\nТочки 3 трикутника : \n");
  printRightTriangle(Triangle3);
  printf("Площа 3 трикутника : %f", areaRightTriangle(Triangle3));
  
  
  
  destroyRightTriangle(Triangle);//видаляємо трикутник
  destroyRightTriangle(Triangle2);
  destroyRightTriangle(Triangle3);
  destroy_massive(massive);// видаляємо масив точок
  return 0 ;
}
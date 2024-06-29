#include "dopom.h"
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include "point.h"

Point *create_massivePoint(Point *p1 , Point *p2 , Point *p3){//функція створення масиву точок
  Point *result = (Point *)malloc(3 * sizeof(Point));
  if(NULL == p1 || NULL == p2 || NULL == p3){
    return NULL;//якщо не існують точки
  }
  result[0] = *p1;//надаємо значення
  result[1] = *p2;
  result[2] = *p3;
  return result;//вертаємо масив точок
}

void destroy_massive(Point *massive){//фунція знищення масиву точок
  if(NULL== massive){
    return  ;
  }
  free(massive);//звільняємо память від масиву

}
#include <stdio.h>
#include <stdlib.h>
#include "point.h"

  Point *createPoint(float x, float y){// функція створення точок
  Point *result = (Point *)malloc(sizeof(Point));//виділення памяті для точки
  if(NULL != result){
    result->x = x;//надаємо координати
    result->y = y;
    }
    
  return result;//вертаємо точку
}

void destroiPoint(Point *aPoint){//функція знищення точок
  if(NULL!= aPoint){//перевірка на пустоту
    free(aPoint);//звільняємо память
  }
}

void printPoint(Point *aPoint){//функція виводу точок
  if(NULL == aPoint){
    printf("Invalid Object");// виводимо помилку
    return ;
  }
  printf("(%f,%f)\n", aPoint->x, aPoint->y);// виводимо кординати точки
}

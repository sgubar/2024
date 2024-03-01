#ifndef point_h
#define point_h

#include <stdio.h>

typedef struct tPoint {//створюємо структуру точки з координатами
  float x;
  float y;
}Point;//назва визову структури

Point *createPoint(float x, float y);// функція створення точок

void destroiPoint(Point *aPoint);//функція знищення точок

void printPoint(Point *aPoint);//функція виводу точок



#endif 
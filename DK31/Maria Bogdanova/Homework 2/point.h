#ifndef point_h
#define point_h

#include <stdio.h>

typedef struct tagPoint {
  int x;
  int y;
} Point, *PPoint; //Створюємо структуру та вказівник на неї

Point *createPoint(int x, int y); //функція для створення точки
void destroyPoint(Point *P); //функція для видалення точки
void printPoint(Point *P); //функція для виведення точки

#endif

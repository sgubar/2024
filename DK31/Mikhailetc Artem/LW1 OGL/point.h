#ifndef point_h
#define point_h

#include <stdio.h>

struct tagPoint {
	int x;
	int y;
};
typedef struct tagPoint Point; //структура для точки

Point *createPoint(int x, int y); //створення
Point *copyPoint(Point *a); //копіювання
void deletePoint(Point *a); //видалення
void printPoint(Point *a); //виведення
void fillPoint(Point *a); //заповнення
void setPointValues(Point* point, int x, int y); //значення для точки

#endif

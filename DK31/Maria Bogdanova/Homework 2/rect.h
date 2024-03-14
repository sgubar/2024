#ifndef _rect_h_
#define _rect_h_
#include "point.h"

typedef struct tagRectangle { //задаємо структуру Rectangle 
    Point *A; 
    Point *C; //задаємо точки А та С
} Rectangle;


Rectangle *create_Rectangle(Point *A, Point *C); //функція для створення прямокутника
double calculateRectangleArea(Rectangle *R); //функція для обчислення площі
void destroyRectangle(Rectangle *R);//функція для видалення
void printResult(Rectangle *R);//функція для виведення результату

#endif 

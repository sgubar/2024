#ifndef rec_h
#define rec_h

#include <stdio.h>

struct Point { //Оголошуємо структуру Point для точок
    double x;
    double y;
};
struct Point *createPoint(int x, int y); 
void destroyPoint(struct Point *P); //Оголошує функції createPoint, destroyPoint для роботи з точками
struct Rec {
    struct Point topLeft;     // Ліва верхня точка
    struct Point bottomRight; // Права нижня точка
};
double calculateRectangleArea(struct Rec rect);//Оголошує структуру Rec для прямокутника та функцію calculateRectangleArea для обчислення його площі
#endif

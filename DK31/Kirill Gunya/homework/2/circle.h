#ifndef CIRCLE_H
#define CIRCLE_H
#include "point.h" // Підключення опису структури точки

// Структура для представлення кола
typedef struct {
    Point *center; // Вказівник на центр кола
    float radius;  // Радіус кола
} Circle;

// Прототипи функцій для роботи з колами
Circle *createCircle(Point *center, float radius); // Функція створення кола
void printCircle(Circle *c);                       // Функція виведення інформації про коло
float areaOfCircle(Circle *c);                     // Функція обчислення площі кола
void destroyCircle(Circle *c);                     // Функція знищення кола

#endif

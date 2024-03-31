#ifndef POINT_H
#define POINT_H

// Структура для представлення точки на двовимірній площині
typedef struct {
    float x; // Координата X точки
    float y; // Координата Y точки
} Point;

// Прототипи функцій для роботи з точками
Point *createPoint(float x, float y); // Функція для створення нової точки
void printPoint(Point *p);            // Функція для виведення координат точки
void destroyPoint(Point *p);          // Функція для знищення точки та звільнення ресурсів

#endif

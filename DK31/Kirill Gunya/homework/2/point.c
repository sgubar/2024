#include "point.h"
#include <stdio.h>
#include <stdlib.h>

// Реалізація функцій для роботи з точками
Point *createPoint(float x, float y) {
    Point *newPoint = (Point *)malloc(sizeof(Point)); // Виділення пам'яті для нової точки
    if (newPoint != NULL) { // Якщо пам'ять успішно виділена
        newPoint->x = x;    // Задаємо координату X
        newPoint->y = y;    // Задаємо координату Y
    }
    return newPoint;        // Повертаємо вказівник на нову точку
}

void printPoint(Point *p) {
    if (p != NULL) { // Перевірка, чи точка не є NULL
        printf("(%f, %f)", p->x, p->y); // Друк координат точки
    } else {
        printf("Invalid point\n");
    }
}

void destroyPoint(Point *p) {
    free(p); // Звільнення пам'яті, виділеної під точку
}

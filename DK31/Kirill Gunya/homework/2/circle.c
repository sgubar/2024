#include "circle.h"
#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>

Circle *createCircle(Point *center, float radius) {
    if (radius <= 0) { // Перевірка, чи радіус більше нуля
        printf("Радіус має бути більше нуля\n");
        return NULL;
    }
    Circle *newCircle = (Circle *)malloc(sizeof(Circle)); // Виділення пам'яті для кола
    if (newCircle != NULL) { // Якщо пам'ять успішно виділена
        newCircle->center = createPoint(center->x, center->y); // Встановлення центру кола
        newCircle->radius = radius; // Встановлення радіуса кола
    }
    return newCircle; // Повертаємо вказівник на новостворене коло
}

// Функція для обчислення площі кола
float areaOfCircle(Circle *c) {
    if (c == NULL) { // Перевірка, чи коло не є NULL
        printf("The circle does not exist\n");
        return 0.0;
    }
    return M_PI * pow(c->radius, 2); // Формула для обчислення площі кола
}

// Функція для виведення інформації про коло
void printCircle(Circle *c) {
    if (c == NULL || c->center == NULL) { // Перевірка, чи коло і його центр існують
        printf("Invalid circle or circle center\n");
        return;
    }
    printf("A circle with a center ");
    printPoint(c->center); // Виклик функції для друку координат центру кола
    printf(" and radius %.2f\n", c->radius);
}

// Функція для знищення кола
void destroyCircle(Circle *c) {
    if (c != NULL) {
        destroyPoint(c->center); // Звільнення пам'яті, виділеної для центру кола
        free(c); // Звільнення пам'яті, виділеної для самого кола
    }
}

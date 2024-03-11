//
// Created by Nazar Pechkovsky on 10.03.2024.
//

#define CRT_SECURE_NO_WARNINGS
#include "circle.h"
#include "point.h"
#include "help_tool.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

Point *createCords() //Вводимо координати
{
    Point *cords = createPoint(0, 0);
    float x, y;

    printf("x: ");
    while (scanf("%f", &x) != 1)
    {
        printf("Invalid value. Please enter a number: ");
        while (getchar() != '\n'); // Очищення буфера введення
        printf("\nx: ");
    }
    cords->x = x;

    printf("y: ");
    while (scanf("%f", &y) != 1)
    {
        printf("Invalid value. Please enter a number");
        while (getchar() != '\n');
        printf("\ny: ");
    }
    cords->y = y;

    return cords;
}

Circle *createCircleByPoints(Point *O, Point *K) //Створення кола по точкам
{

    Circle *newCir = (Circle *) malloc(sizeof(Circle));
    if(O == NULL || K == NULL)
    {
        return NULL;
    }

    newCir->pCen = createPoint(O->x, O->y);
    newCir->pCir = createPoint(K->x, K->y);

    return newCir;
}

float calculateRadius(Circle *circle) //Створюємо радіус
{
    float rad;
    rad = Exp((circle->pCen->x - circle->pCir->x)) + Exp((circle->pCen->y - circle->pCir->y));
    rad = Sqrt(rad);
    return rad;
}

float calculateCircleArea(Circle *circle, float radius) //Обчислення площі кола
{
    float area;
    area = M_PI * Exp(radius); //M_PI - число пі із бібліотеки math.h

    return area;
}

float calculateCirclePerimeter(Circle *circle, float radius) //Обчислення периметру кола
{
    float perimeter;
    perimeter = 2.00 * M_PI * radius;
    return perimeter;
}

void destroyCircle(Circle *circle) //Знищення кола
{
    if(circle != NULL)
    {
        destroyPoint(circle->pCen);
        destroyPoint(circle->pCir);
        free(circle);
    }
}


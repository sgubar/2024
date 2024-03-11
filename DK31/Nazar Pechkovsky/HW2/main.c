#include <stdio.h>
#include "circle.h"
#include "point.h"
#include "interface.h"

int main(void) {
    interfaceCir_Empty(); //Виведення порожнього інтерфейсу
    printf("Enter the coordinates for point O:\n");
    Point *O = createCords(); //Задати координати точки О
    printf("Enter the coordinates for point K:\n");
    Point *K = createCords(); //Задати координати точки О

    Circle *MyCircle = createCircleByPoints(O, K); //Створюємо коло
    //Знищуємо точки
    destroyPoint(O);
    destroyPoint(K);

    float radiusMyCircle = calculateRadius(MyCircle); //Обрахунок радіуса
    float areaMyCircle = calculateCircleArea(MyCircle, radiusMyCircle); //Обрахунок площі
    float perimeterMyCircle = calculateCirclePerimeter(MyCircle, radiusMyCircle); //Обрахунок периметру

    //Виведення заповненого інтерфейсу
    interfaceCir_Full(MyCircle, radiusMyCircle, perimeterMyCircle, areaMyCircle);
    destroyCircle(MyCircle); //Знищення кола
}

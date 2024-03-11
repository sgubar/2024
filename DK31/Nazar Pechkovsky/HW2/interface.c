//
// Created by Nazar Pechkovsky on 11.03.2024.
//

#include "interface.h"
#include "circle.h"
#include <stdio.h>

void interfaceCir_Empty() //Порожній інтерфейс
{
    printf("Welcome! This is my program that will help you create a circle by points and calculate its area and perimeter\n");
    printf("Please enter cords of circle\n"
           "      *********          \n"
           "    **         **        \n"
           "  **          R  **      \n"
           "  *       *-------* K    \n"
           "  **      O      **      \n"
           "    **         **         \n"
           "      *********          \n\n");
}

void interfaceCir_Full(Circle *circle, float radius, float perimeter, float area) //Заповнений інтерфейс
{
    printf("Result:\n"
           "      *********                      \n"
           "    **         **      O(%.2f, %.2f) \n"
           "  **          R  **    K(%.2f, %.2f) \n"
           "  *       *-------* K  R=%.2f        \n"
           "  **      O      **    P=%.2f        \n"
           "    **         **      S=%.2f        \n"
           "      *********                      \n\n", circle->pCen->x, circle->pCen->y, circle->pCir->x, circle->pCir->y, radius, perimeter, area);
}
//
// Created by Nazar Pechkovsky on 11.03.2024.
//

#include "help_tool.h"
#include <stdio.h>
#include <math.h>

float Sqrt(float num) //Обчислення квадратного кореню
{
    if (num < 0) {
    printf("Error: the square root of a negative number is undefined in real numbers\n");
    return -1;
    }

    float epsilon = 0.00001; //Точність яку можна регулювати
    float guess = num / 2.0; // Початкова наближена вартість кореня

    //fabs (math.h) - модуль числа
    while (fabs(guess * guess - num) > epsilon) {
        guess = 0.5 * (guess + num / guess);
    }
    return guess;
}

float Exp(float x) //Обчислення степеня
{
    float exp = x * x;
    return exp;
}


#include <stdio.h>
#include <math.h>
#include "math.h" 

int value(int a) // функція вводу змінних
{
    int A;
    printf("Значення %i = ", a);
    scanf("%d", &A);

    return A;
}

long factorial(int num) // функція для знаходження факторіалу 
{
    long rez = 1;
    if (num < 0) {
        return -1;
    }
    for (int i = 1; i <= num; i++) {
        rez *= i;
    }
    return rez;
}

long sum_factorial(int start, int finish, int x) // функція для знаходження суми факторіалів
{
    long rez = 0;
    for (int i = start; i <= finish; i++) {
        rez += factorial(x + i);
    }
    return rez;
}

double q(int a, int b, int c) // функція основної формули 
{
    return a * sqrt(b + c) / b + (double)sum_factorial(0, c, a);
}

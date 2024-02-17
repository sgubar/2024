#include <stdio.h>
#include <cs50.h>
#include "math.h"

int main() {
    int *m = get_ABC(); // створюємо масив та вписуємо 3 числа , і перевіріємо їх на коректність використання в прикладі
    printf("%f\n", q(m[0], m[1], m[2]));// виводимо результат
    destroy_mas(m);// видаляємо масив
}

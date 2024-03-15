#include <stdio.h>
#include <stdlib.h>
#include "list_double.h"

int main(void) {
    ListDoubl *List = createListDoubl();//стоврюємо список 
    double a = 10.0;//створюємо значення типу double
    double b = 42.0;
    double c = 124.0;
    double f = 1204.0;
    double p = 90.0;
    double i = 12074.0;
    double e = 16782.0;
    int A = addListDoubl(List, &a);//додаємо вкінець списку значення
    int B = addListDoubl(List, &b);
    int C = addListDoubl(List, &c);
    int F = addListDoublAt(List, &f, 0);//додаємо в список за індексом значення
    F = addListDoublAt(List, &p, 4);
    F = addListDoublAt(List, &i, 3);
    F = addListDoublAt(List, &e, 3);
    F = addListDoublAt(List, &e, 0);
    F = addListDoublAt(List, &f, 0);
   destroyLastDoubleInLIst(List);
   destroyFirstDoubleInLIst(List);
  
   // destroyDoubleInLIst(List, 9);//видаляємо елемент за індексом у списку
    printf( "Кількість елементів в списку : %d\n", countListDoubl(List));//виводимо кількість елементів у списку
    printListDoubl(List);//виводимо список
    destroyListDoubl(List);//видаляємо список
    
    return 0;
}
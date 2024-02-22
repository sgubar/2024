#include <stdio.h>
#include <ctype.h>
#include "math_tool.h"

int main(void) {
  long int a, b,c;
  do{
  printf("Введіть натуральне значення A\n");
  scanf("%li", &a);
  }while(a<0);
  printf("Введіть натуральне значення B\n");
  scanf("%li", &b);
  do{
    printf("Введіть натуральне значення C\n");
    scanf("%li", &c);
  }while(c==0);

  float k,l,m,n;
  k=math_modulos(sub(mul(a, c), b));
  l= div(k, power(c,3));
  n = mul(l, algebra_sum_power_of_two(0, c));
  printf( "Результат |A*C-B|= %f\n", k);
  printf( "Результат |A*C-B|/C^3= %f\n", l);
  printf( "Кінцевий результат %f\n", n);
  
}
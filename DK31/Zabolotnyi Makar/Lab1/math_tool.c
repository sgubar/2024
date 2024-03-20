#include "math_tool.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>

int add(int a, int b) {
  return a + b;
}

int sub(int a, int b) {
  return a - b;
}

int mul(int a, int b) {
  return a * b;
}

int div(int a, int b) {
  if (b != 0) {
  return a / b;}
  else {
    printf("Error: Division by zero\n");
}}

int power(int a, int b) {
  int c = 1;
  for (int i = 0; i < b; i++) {
    c *= a;
  }
  return c;
}

int algebra_sum_power_of_two(int a, int b){
  int c = 0;
  for (int i = a; i <= b; i++){
    c += power(2, i);
    
  }
  return c;}

int math_modulos(int a){
  if (a<0){
    a = a * -1;
    return a;
  }
  else return a;
}  

int check_natural(){
  // функція для перевірки натуральності числа
  char input[10];
  printf("Введіть натуральне значення A\n ");
  fgets(input, sizeof(input), stdin);
  int x = strlen(input);
  int i = 0;
      while (input[i] != '\0' ) {
          if (ispunct(input[i])) {
            return 0;
            break;
          }

          i++;
      }

      if (input[i] == '\0') {
        unsigned int a=0;
        for(int i=0;i<x-1;i++){
          a = a*10 + (input[i]-'0');
        }
        return a;}
  
  }
  

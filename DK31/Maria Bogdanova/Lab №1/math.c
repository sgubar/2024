#include "math.h"

#define MOD(n) (n < 0 ? -n : n) 
// (condition) ? <> : <> 
//Використовуємо тернарний оператор

double power(int base, int pow) { // power обчислює base в степені pow

  double result = 1;
  int pw = MOD(pow); //використовується MOD для визначення абсолютного значення pow
  for (int i = 0; i < pw; i ++) { //цикл для множення base на себе pw разів. Якщо pow від'ємне, результат повертається як 1.0 / result
    result *= base;
  }
  return (pow < 0) ? 1.0 / result : result; //тернарний оператор
}

int q(int A, int B, int C, int D) {
 if (C==0){ 
   while (getchar() !='\n');//програма чекає, доки користувач натисне Enter,виводить повідомлення і потім завершує своє виконання за допомогою функції exit(0)
   printf("С не може бути рівним нулю "); 
   exit(0);
 }
  int M=(A*B)-C;
    if (M < 0) {///Цикл для обчислення модуля (використовуємо MOD(n))
        return MOD(M)/(power(C, 3))*(A+B+C+D)*power(2, D);
    }else {
      return (M)/(power(C, 3))*(A+B+C+D)*power(2, D);
    }
}

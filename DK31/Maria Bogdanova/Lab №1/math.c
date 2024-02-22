#include "math.h"

#define MOD(n) (n < 0 ? -n : n) // (condition) ? <> : <>
//Використовуємо тернарний оператор

double power(int base, int pow) // power обчислює base в степені pow
{
  double result = 1;
  int pw = MOD(pow); //використовується MOD для визначення абсолютного значення pow
  for (int i = 0; i < pw; i ++) {
    result *= base; 
  }
  return (pow < 0) ? 1.0 / result : result; //цикл для множення base на себе pw разів. Якщо pow від'ємне, результат повертається як 1.0 / result
}

double q(int A, int B, int C, int D) {
  int M=(A*B)-C; 
    if (M < 0) {  ///Цикл для обчислення модуля
        return (-M)/(power(C, 3))*(A+B+C+D)*power(2, D);
    }else {
      return (M)/(power(C, 3))*(A+B+C+D)*power(2, D);
    }
}

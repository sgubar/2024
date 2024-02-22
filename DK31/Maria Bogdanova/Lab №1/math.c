#include "math.h"

#define MOD(n) (n < 0 ? -n : n) // (condition) ? <> : <>

double power(int base, int pow) {

  double result = 1;
  int pw = MOD(pow);
  for (int i = 0; i < pw; i ++) {
    result *= base;
  }
  return (pow < 0) ? 1.0 / result : result;
}

double q(int A, int B, int C, int D) {
  int M=(A*B)-C; 
    if (M < 0) {
        // Виведення повідомлення про неправильне число
        return (-M)/(power(C, 3))*(A+B+C+D)*power(2, D);
    }else {
      return (M)/(power(C, 3))*(A+B+C+D)*power(2, D);
    }
}

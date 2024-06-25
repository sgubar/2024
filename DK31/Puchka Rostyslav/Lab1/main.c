#include "my_math.h"
#include <stdio.h>

int main(void) {
  int A;
  float B;

  // print a message with the requirements for numbers
  printf("A must be nonnegative and integer.\n2*A == -B must be false.\n");
  // read numbers
  read_A_and_B(&A, &B);

  // calculate result
  float result = calculate(A, B);
  // print result
  printf("Result: %f", result);

  return 0;
}
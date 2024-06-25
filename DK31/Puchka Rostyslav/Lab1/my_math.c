#include <stdio.h>

int factorial(int number) {
  int result = 1;

  while (number != 0) {
    result *= number;
    number--;
  }

  return result;
}

float modulo(float number) {
  if (number < 0) {
    return -number;
  } else {
    return number;
  }
}

float calculate(int A, float B) { return factorial(A) / modulo(2 * A + B); }

void read_A_and_B(int *A, float *B) {
  // create temporarly float
  float A_tmp = -1;

  printf("A: "); // ask for A
  scanf("%f", &A_tmp);

  // check is float not negatibe and don't has fractional
  while (A_tmp < 0 || A_tmp != (int)A_tmp) {
    while (getchar() != '\n')
      ; // clean input buffer

    // print error message
    printf("Number A must be not negative and integer!\n");
    printf("A: "); // ask for A one more time
    scanf("%f", &A_tmp);
  }

  *A = (int)A_tmp; // save A to original variable

  while (getchar() != '\n')
    ;            // clean buffer
  printf("B: "); // ask for B
  while (scanf("%f", B) != 1) {
    while (getchar() != '\n')
      ;                      // clean buffer
    printf("B must be float!\n"); // print error message
    printf("B: ");           // ask for B one more time
  }

  // check for division by zero
  if (2 * (*A) == -(*B)) {
    printf("Error: 2*A == -B\n"); // print error message
    read_A_and_B(A, B);           // ask for numbers one more time
  }
}
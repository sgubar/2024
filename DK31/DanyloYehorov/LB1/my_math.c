#include "my_math.h"

#include <stdlib.h>
#include <stdio.h>

void read_str(char str[], unsigned int str_size, char prompt[]) {
    printf("%s", prompt);                       // print prompt
    int i = 0;
    while ((str[i] = getchar()) != EOF) {
        if (str[i] == '\n') {                   // newline character -> end of the input string
            str[i] = '\0';                      // replace '\n' with '\0'
            break;
        } else if (i == str_size) {             // input string is not over, but buffer is about to overflow
            str[i] = '\0';                      // put '\0' at the end
            while (getchar() != '\n');          // clean the input buffer
            break;
        }
        i++;
    }
}

int factorial(int num) {
    if (num == 0) {
        return 1;
    }

    int res = 1;
    int old_res;

    while (num != 1) {
        old_res = res;                          // save old res for overflow detection
        res *= num--;                           // multiply res by next num
        if (old_res > res) {                    // if new res is greater than new -> overflow
            printf("Overflow detected! Result will be wrong!\n");
            return -1;
        }
    }

    return res;
}

float modulo(float num) {
        return (num < 0 ? -num : num);
}

float *read_nums(int quntity, char *letters) {
    const int buf_len = 32;

    char input_buf[buf_len + 1];                                 // input buffer
    float *nums_ptr = (float*) malloc(quntity * sizeof(float));  // allocate memory for nums

    if (nums_ptr == NULL) {                                      // check if the pointer valid
        printf("Can't allocate memory!\n");
        return NULL;
    }

    int i;
    for (i = 0; i < quntity; i++) {
        printf("%c: ", *(letters++));       // print promt
        read_str(input_buf, buf_len, "");   // read string
        nums_ptr[i] = atof(input_buf);      // parse number

        // if values invalid -> read until number is obtained
        // --------------------------------------------------
        // atoi returns 0 if no number is found
        // so result 0 is valid only when
        // the first letter of the input is '0'
        while (nums_ptr[i] == 0 && input_buf[0] != '0') {
            printf("%c: ", *(letters-1));     // print promt
            read_str(input_buf, 20, "");      // read string
              nums_ptr[i] = atoi(input_buf);  // parse number
        }
    }

    return nums_ptr;
}



void read_AB(int *A, float *B) {
    printf("Enter numbers A and B.\n"
         "A must be a nonnegative integer.\n"
         "The mathematical expression\n"
         "         A * 2 + B = 0\n"
         "must be false.\n\n");

    float *nums;

    nums = read_nums(2, "AB");                  // read numbers
    // if nums not correct -> read values until: A > 0    A*2 != -B    A is integer
    while (nums[0] < 0 || (nums[0] * 2 == -nums[1]) || (((float) (int) nums[0]) != nums[0])) {
        destroy_nums(nums);                     // clean memory
        nums = read_nums(2, "AB");              // read one more time
    }

    *A = (int) nums[0];                         // save A and B to variables
    *B = nums[1];

    destroy_nums(nums);                         // clean memory
}



void destroy_nums(float *nums) {
    if (nums == NULL) {                       // check if the pointer valid
        printf("Pointer is invalid\n");
        return;
    }

    free(nums);
}

float calc(int A, float B) {
    return factorial(A) / modulo(2*A + B);
}

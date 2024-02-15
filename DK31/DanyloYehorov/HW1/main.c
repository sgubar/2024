#include <stdio.h>
#include "dk_tool.h"

#define MAIN_SIZE   32
#define SEARCH_SIZE 32

#define DEBUG       0

int main(void) {
    // create variables for strings (additional byte for '\0')
    char main_str[MAIN_SIZE+1];
    char search_str[SEARCH_SIZE+1];

    // read strings
    read_str(main_str, MAIN_SIZE, "Enter a string: ");
    read_str(search_str, SEARCH_SIZE, "Enter a search string: ");

    #if DEBUG == 1
    int i;
    printf("\nmain str:   %s\nsearch_str: %s\n", main_str, search_str);
    for (i = 0; i < MAIN_SIZE + 2; i++) {
        printf("%d ", main_str[i]);
    }
    printf("\n");

    for (i = 0; i < SEARCH_SIZE + 2; i++) {
        printf("%d ", search_str[i]);
    }
    printf("\n");
    #endif

    // search for string and print result
    int result = find_str(main_str, search_str);
    printf(result == -1 ? "String not found!\n" : "String found! Entry point: %d.\n", result);

    return 0;
}

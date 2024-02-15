#include "dk_tool.h"
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

int find_str(char *main_txt, char *search_txt) {
    unsigned int search_i = 0;                  // variable for the search string index
    unsigned int main_i;                        // variable for the main string index
    unsigned int entry_i;                       // variable for the (possible) entry point

    if (main_txt == NULL) {                     // check if main_txt pointer is correct
        printf("Invalid pointer to string (main_txt)!\n");
        return -1;
    }
    if (search_txt == NULL) {                   // check if search_txt pointer is correct
        printf("Invalid pointer to string (search_txt)!\n");
        return -1;
    }


    for (main_i = 0; main_txt[main_i] != '\0'; main_i++) {
        // if the end of the main string is reached
        if (main_txt[main_i] == '\0') {
            return -1;
        }
        // if characters don't match -> next turn
        if (main_txt[main_i] != search_txt[search_i]) {
            continue;
        }

        entry_i = main_i;                       // save posible entry point
        search_i++;                             // increment indexes
        main_i++;

        while (1) {
            // if the search text is exhausted -> search string is found -> return entry_i
            if (search_txt[search_i] == '\0') {
                return entry_i;
            }

            // if characters don't match
            if (main_txt[main_i] != search_txt[search_i]) {
                search_i = 0;               // reset search index
                main_i = entry_i;           // return index of the "possible" entry point

                break;                      // break out of the loop
            } else {                        // else if characters match
                main_i++;                   // increment indexes
                search_i++;
            }
        }
    }

    return -1;
}

#include "dk_tool.h"
#include <string.h>

int count_occurrences(char *sentence, char *sequence) {
    int count = 0;
    int seq_len = strlen(sequence);
    int sen_len = strlen(sentence);

    for (int i = 0; i <= sen_len - seq_len; i++) {
        int j;
        for (j = 0; j < seq_len; j++) {
            if (sentence[i + j] != sequence[j]) {
                break;
            }
        }

        if (j == seq_len) {
            count++;
        }
    }

    return count;
}

void remove_newline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

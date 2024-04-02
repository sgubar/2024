#include "dk_tool.h"
#include <string.h>

int count_occurrences(char *sentence, char *sequence) {
    int count = 0;
    int seq_len = strlen(sequence);
    int sen_len = strlen(sentence);
    
    // Ітеруєм    ся по рядку
    for (int i = 0; i <= sen_len - seq_len; i++) {
        int j;
        // Перевіряємо, чи співпадає послідовність
        for (j = 0; j < seq_len; j++) {
            if (sentence[i + j] != sequence[j]) {
                break;
            }
        }
        // Якщо всі символи послідовності співпадають, збільшуємо лічильник
        if (j == seq_len) {
            count++;
        }
    }
    return count;
}

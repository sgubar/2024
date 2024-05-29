#include <stdio.h>
#include "dk_tool.h"

int main() {
    char sentence[100];
    char sequence[20];

    printf("Введіть речення: ");
    fgets(sentence, sizeof(sentence), stdin);

    remove_newline(sentence); 
    printf("Введіть послідовність: ");
    fgets(sequence, sizeof(sequence), stdin);

    remove_newline(sequence);  

    int occurrences = count_occurrences(sentence, sequence);

    printf("Кількість входжень послідовності у реченні: %d\n", occurrences);

    return 0;
}

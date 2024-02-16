#include <stdio.h>
#include <string.h>
#include "dk_tool.h"


int main() {
    char sentence[1000];

    printf("Введіть речення: ");
    fgets(sentence, sizeof(sentence), stdin);

    int words = countWords(sentence);
    printf("Кількість слів в реченні: %d\n", words);

    return 0;
}

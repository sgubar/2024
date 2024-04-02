#include <stdio.h>
#include "dk_tool.h"

int main() {
    char sentence[100];
    char sequence[20];
    
    // Введення речення
    printf("Введіть речення: ");
    fgets(sentence, sizeof(sentence), stdin);
    
    // Введення послідовності
    printf("Введіть послідовність: ");
    fgets(sequence, sizeof(sequence), stdin);
    
    // Підрахунок кількості входжень послідовності в реченні
    int occurrences = count_occurrences(sentence, sequence);
    
    // Виведення результату
    printf("Кількість входжень послідовності у реченні: %d\n", occurrences);
    
    return 0;
}

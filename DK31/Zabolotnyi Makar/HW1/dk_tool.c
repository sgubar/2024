#include "dk_tool.h"

int countWords(char sentence[]) {
    int i,l, wordCount, isWord;
    l =  strlen(sentence);

    wordCount = 0;
    isWord = 0;

    // Проходимо через кожен символ речення
    for (i = 0; i < l; i++) {
        // Якщо поточний символ - буква або цифра, вважаємо його частиною слова
        if ((sentence[i] >= 'a' && sentence[i] <= 'z') || (sentence[i] >= 'A' && sentence[i] <= 'Z') || (sentence[i] >= '0' && sentence[i] <= '9')) {
            isWord = 1;
        }
        // Якщо поточний символ - не буква або цифра, а попередній був, то збільшуємо лічильник слів
        else if (isWord) {
            wordCount++;
            isWord = 0;
        }
    }

    // Якщо останній символ - буква або цифра, збільшуємо лічильник слів
    if (isWord) {
        wordCount++;
    }

    return wordCount;
}

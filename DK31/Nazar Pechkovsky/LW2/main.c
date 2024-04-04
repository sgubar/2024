//
//Знайти середнє арифметичне елементів послідовності, що складається з чисел, видалити перше, менше за середнє.
//
#define SECURE_NO_WARNINGS

#include <stdio.h>
#include "list.h"

int main() {
    StartOfList *list = CreateFirstElementInList();
    char answer;
    int count = 0;
    do {
        printf("Enter an integer number: ");
        int number = InputInt();
        AddElementInList(list, number);
        count++;
        PrintList(list);
        printf("Do you want to continue? (y/n): ");
        clearInputBuffer();
        scanf("%c", &answer);
    } while (answer == 'y');

    if (answer != 'n') {
        printf("Invalid input. Exiting...\n");
    }
    else if(count < 2) {
        printf("You entered less than 2 numbers. Exiting...\n");
    }
    else {
        DeleteFirstElementLessThanAverage(list);
    }
    DeleteList(list);
    return 0;
}
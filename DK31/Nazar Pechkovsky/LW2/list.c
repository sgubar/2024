#include "list.h"
#include <stdlib.h>
#include <stdio.h>

// Перевірка на помилку виділення пам'яті
void checkAllocation(void *a)
{
    if (a == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
}

// Створення початкової точки списку
StartOfList *CreateFirstElementInList(void)
{
    StartOfList *result = (StartOfList *)malloc(sizeof(StartOfList));
    checkAllocation(result);
    result->head = NULL;
    return result;
}

// Додавання елемента у кінець списку
void AddElementInList(StartOfList *list, int value)
{
    checkAllocation(list);

    ElementInList *newElement = (ElementInList *)malloc(sizeof(ElementInList));
    checkAllocation(newElement);

    newElement->value = value;
    newElement->next = NULL;
    if (list->head == NULL) {
        // Якщо список порожній, то новий елемент стає його головним елементом
        list->head = newElement;
    } else {
        // Інакше потрібно пройтися по списку і додати новий елемент в кінець
        ElementInList *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newElement;
    }
}

// Обробка некоректного введення
int InputInt()
{
    int num;
    while (scanf("%d", &num) != 1) {
        printf("Invalid input. Please enter an integer: ");
        while (getchar() != '\n');
    }
    return num;
}

// Видалення всіх елементів списку
void DeleteList(StartOfList *list)
{
    if (list == NULL)
        return;

    ElementInList *current = list->head;
    ElementInList *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

// Видалення першого елемента, значення якого менше за середнє значення всіх елементів у списку
void DeleteFirstElementLessThanAverage(StartOfList *list)
{
    if (list == NULL || list->head == NULL)
        return;

    double average = CountAverage(list);
    printf("Average: %.2f\n", average);

    ElementInList *current = list->head;
    ElementInList *prev = NULL;

    while (current != NULL) {
        if (current->value < average) {
            if (prev == NULL) {
                list->head = current->next;
            }
            else {
                prev->next = current->next;
            }
            ElementInList *temp = current;
            current = current->next;
            free(temp);
            break;
        } else {
            prev = current;
            current = current->next;
        }
    }

    PrintList(list);
}

// Підрахунок середнього значення у списку
double CountAverage(StartOfList *list)
{
    if (list == NULL || list->head == NULL)
        return 0;

    ElementInList *current = list->head;
    int sum = 0, count = 0;

    while (current != NULL) {
        sum += current->value;
        count++;
        current = current->next;
    }

    return (double)sum / count;
}

// Виведення елементів списку
void PrintList(StartOfList *list)
{
    if (list == NULL || list->head == NULL) {
        printf("List is empty or NULL!\n");
        return;
    }

    printf("List: ");
    ElementInList *current = list->head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

// Очищення буфера вводу
void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
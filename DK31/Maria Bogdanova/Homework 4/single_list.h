#ifndef single_list_h
#define single_list_h

#include <stdio.h>

typedef struct tagSingleListFloatElement { //структура для елементу однозвязного списку

struct tagSingleListFloatElement *next; //next - вказівник на наступний елемент
float value; //наш список зберігатиме значення value

} SingleListFloatElement; //назва структури

SingleListFloatElement *createSingleListFloatElement(float value); //функція для створення елемента
void deleteSingleListFloatElement(SingleListFloatElement *element);//функція для видалення елемента
void printSingleListFloatElement(SingleListFloatElement *element);//функція для виведення елемента

typedef struct tagFloatSingleList { //структура для списку
 SingleListFloatElement *head; //початок (голова) списку
} FloatSingleList; //назва структури

FloatSingleList *createFloatSingleList(void); //функція для створення списку
void deleteFloatSingleList(FloatSingleList *list); //функція для видалення списку
void printFloatSingleList(FloatSingleList *list); //функція для виведення списку

long countOfFloatSingleList(FloatSingleList *list); //функція для підрахунку кількості елементів
float addFloatValueToFloatSingleList(FloatSingleList *list, float value); //функція для додавання елементу до списку
void removeLastElementFromFloatSingleList(FloatSingleList *list); //функція для видалення останнього елементу
void removeFirstElementFromFloatSingleList(FloatSingleList *list); //функція для видалення першого елементу

float insertFloatElementToFloatSingleListAtIndex(FloatSingleList *list, float index, float value); //функція для додавання елементу за індеком
float removeFloatElementFromFloatSingleListAtIndex(FloatSingleList *list, float index); //функція для видалення елементу за індеком

#endif

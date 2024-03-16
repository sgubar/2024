#ifndef single_list_h
#define single_list_h

#include <stdio.h>

typedef struct tagSingleListFloatElement {

struct tagSingleListFloatElement *next;
float value;

} SingleListFloatElement;

SingleListFloatElement *createSingleListFloatElement(float value);
void deleteSingleListFloatElement(SingleListFloatElement *element);
void printSingleListFloatElement(SingleListFloatElement *element);

typedef struct tagFloatSingleList{
 SingleListFloatElement *head; 
//long count;
} FloatSingleList;

FloatSingleList *createFloatSingleList(void);
void deleteFloatSingleList(FloatSingleList *list);
void printFloatSingleList(FloatSingleList *list);

long countOfFloatSingleList(FloatSingleList *list);
float addFloatValueToFloatSingleList(FloatSingleList *list, float value);
void removeLastElementFromFloatSingleList(FloatSingleList *list);
void removeFirstElementFromFloatSingleList(FloatSingleList *list);

float insertFloatElementToFloatSingleListAtIndex(FloatSingleList *list, float index, float value);
float removeFloatElementFromFloatSingleListAtIndex(FloatSingleList *list, float index);

#endif

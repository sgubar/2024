#ifndef triangle_h
#define triangle_h

#include <stdio.h>
#include "point.h"
#define NUM 3


// Колір як стурктура
typedef struct Color_s{
    float R;
    float G;
    float B;
} Color_s;
// Методи для роботи з кольором
Color_s* createColor(float R, float G, float B);
void deleteColor(Color_s* color);

typedef struct tagTriangle{
  Point* points[NUM]; // в даній роботі координати мають значення від [-100;100], але потім масштабуються до [-1;1] як цього потребує OpenGL
  Color_s* color;
} Triangle;

Triangle *createTriangle(Point** points, Color_s * color);

void destroyTriangle(Triangle *aTriangle); // функція знищення трикутника
void printTriangle(Triangle *aTriangle); // функція друку трикутника


typedef struct TriangleListElement_s{
    TriangleListElement_s* prev;
    TriangleListElement_s* next;
    Triangle* triangle;
} TriangleListElement_s;
// Методи для роботи з елементом списку трикутників
TriangleListElement_s* createListElement(Triangle* triangle);
void deleteListElement(TriangleListElement_s* listElement);
void drawListElement(TriangleListElement_s* listElement);


typedef struct TriangleList_s{
    TriangleListElement_s* head;
    TriangleListElement_s* tail;
} TriangleList_s;
// Методи для роботи зі списком трикутників
TriangleList_s *createTriList(void);
void deleteTriList(TriangleList_s *list);
void drawTriList(TriangleList_s *list);
long countOfTriList(TriangleList_s *list);
int addTriToTriList(TriangleList_s *list, Triangle* triangle); // 1 - успіх, 0 - провал
void removeLastElementFromTriList(TriangleList_s *list);
void removeFirstElementFromTriList(TriangleList_s *list);
int insertTriToTriListAtIndex(TriangleList_s *list, int index, Triangle* triangle); // 1 - успіх, 0 - провал
int removeTriFromTriListAtIndex(TriangleList_s *list, int index); // 1 - успіх, 0 - провал

#endif

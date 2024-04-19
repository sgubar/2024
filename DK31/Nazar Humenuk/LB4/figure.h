
#ifndef figure_h
#define figure_h

#include <stdio.h>
#include "point.h"

// Призначаємо кілкьість точок в фігурі
#define PT_NUM 3


// Колір як стурктура
typedef struct Color_s{
    float R;
    float G;
    float B;
} Color_s;
// Методи для роботи з кольором
Color_s* createColor(float R, float G, float B);
void deleteColor(Color_s* color);


// Фігура як масив точок з кольором
typedef struct tagRightTriangle{
    Point* points[PT_NUM]; // ВАЖЛИВО: в прикладі координати мають значення від [-100;100], але потім масштабуються до [-1;1] як цього потребує OpenGL
    Color_s* color;
} RTrgle;
// Методи для роботи з фігурою
RTrgle* createRTrgle(Point** points, Color_s * color);
void deleteRTrgle(RTrgle* figure);
void drawRTrgle(RTrgle* figure);


// Елемент списку фігур
typedef struct RTrgleListElement_s{
    RTrgleListElement_s* prev;
    RTrgleListElement_s* next;
    RTrgle* figure;
} RTrgleListElement_s;
// Методи для роботи з елементом списку фігур
RTrgleListElement_s* createListElement(RTrgle* figure);
void deleteListElement(RTrgleListElement_s* listElement);
void drawListElement(RTrgleListElement_s* listElement);


// Двозв'язний список фігур
typedef struct RTrgleList_s{
    RTrgleListElement_s* head;
    RTrgleListElement_s* tail;
} RTrgleList_s;
// Методи для роботи зі списком фігур
RTrgleList_s *createFigList(void);
void deleteFigList(RTrgleList_s *list);
void drawFigList(RTrgleList_s *list);
long countOfFigList(RTrgleList_s *list);
int addFigToFigList(RTrgleList_s *list, RTrgle* figure); // 1 - успіх, 0 - провал
void removeLastElementFromFigList(RTrgleList_s *list);
void removeFirstElementFromFigList(RTrgleList_s *list);
int insertFigToFigListAtIndex(RTrgleList_s *list, int index, RTrgle* figure); // 1 - успіх, 0 - провал
int removeFigFromFigListAtIndex(RTrgleList_s *list, int index); // 1 - успіх, 0 - провал

#endif

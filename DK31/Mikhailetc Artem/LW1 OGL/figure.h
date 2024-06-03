#ifndef figure_h
#define figure_h

#include <stdio.h>
#include "point.h"

// Призначаємо кілкьість точок в фігурі (4)
#define PT_NUM 4


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
typedef struct Figure_s{
    Point* points[PT_NUM];
    Color_s* color;
} Figure_s;

Figure_s* createFigure(Point** points, Color_s * color); //створення фігури
void deleteFigure(Figure_s* figure); //видалення
void drawFigure(Figure_s* figure); //малювання


// Елемент списку фігур
typedef struct FigureListElement_s{
    FigureListElement_s* prev; //попередній елемент списку
    FigureListElement_s* next; //наступний
    Figure_s* figure;
} FigureListElement_s;

FigureListElement_s* createListElement(Figure_s* figure); //створення елементу
void deleteListElement(FigureListElement_s* listElement); //видалення елементу
void drawListElement(FigureListElement_s* listElement); //малювання елементу


// Двозв'язний список фігур
typedef struct FigureList_s{
    FigureListElement_s* head;
    FigureListElement_s* tail;
} FigureList_s;
// Методи для роботи зі списком фігур
FigureList_s *createFigList(void); //створення
void deleteFigList(FigureList_s *list); //видалення
void drawFigList(FigureList_s *list); //малювання
long countOfFigList(FigureList_s *list); //підрахунок
int addFigToFigList(FigureList_s *list, Figure_s* figure); //додавання фігури до списку
void removeLastElementFromFigList(FigureList_s *list); //видалення останнього елементу списку
void removeFirstElementFromFigList(FigureList_s *list); //видалення першого елементу списку
int insertFigToFigListAtIndex(FigureList_s *list, int index, Figure_s* figure); //додавання фігури до списку (при заміні)
int removeFigFromFigListAtIndex(FigureList_s *list, int index); //її видалення

#endif

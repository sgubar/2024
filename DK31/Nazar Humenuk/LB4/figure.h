
#ifndef figure_h
#define figure_h

#include <stdio.h>
#include "point.h"

// ���������� �������� ����� � �����
#define PT_NUM 3


// ���� �� ���������
typedef struct Color_s{
    float R;
    float G;
    float B;
} Color_s;
// ������ ��� ������ � ��������
Color_s* createColor(float R, float G, float B);
void deleteColor(Color_s* color);


// Գ���� �� ����� ����� � ��������
typedef struct tagRightTriangle{
    Point* points[PT_NUM]; // �������: � ������� ���������� ����� �������� �� [-100;100], ��� ���� ������������� �� [-1;1] �� ����� ������� OpenGL
    Color_s* color;
} RTrgle;
// ������ ��� ������ � �������
RTrgle* createRTrgle(Point** points, Color_s * color);
void deleteRTrgle(RTrgle* figure);
void drawRTrgle(RTrgle* figure);


// ������� ������ �����
typedef struct RTrgleListElement_s{
    RTrgleListElement_s* prev;
    RTrgleListElement_s* next;
    RTrgle* figure;
} RTrgleListElement_s;
// ������ ��� ������ � ��������� ������ �����
RTrgleListElement_s* createListElement(RTrgle* figure);
void deleteListElement(RTrgleListElement_s* listElement);
void drawListElement(RTrgleListElement_s* listElement);


// �����'����� ������ �����
typedef struct RTrgleList_s{
    RTrgleListElement_s* head;
    RTrgleListElement_s* tail;
} RTrgleList_s;
// ������ ��� ������ � ������� �����
RTrgleList_s *createFigList(void);
void deleteFigList(RTrgleList_s *list);
void drawFigList(RTrgleList_s *list);
long countOfFigList(RTrgleList_s *list);
int addFigToFigList(RTrgleList_s *list, RTrgle* figure); // 1 - ����, 0 - ������
void removeLastElementFromFigList(RTrgleList_s *list);
void removeFirstElementFromFigList(RTrgleList_s *list);
int insertFigToFigListAtIndex(RTrgleList_s *list, int index, RTrgle* figure); // 1 - ����, 0 - ������
int removeFigFromFigListAtIndex(RTrgleList_s *list, int index); // 1 - ����, 0 - ������

#endif

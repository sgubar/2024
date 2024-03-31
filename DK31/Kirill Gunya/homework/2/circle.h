#ifndef CIRCLE_H
#define CIRCLE_H
#include "point.h" // ϳ��������� ����� ��������� �����

// ��������� ��� ������������� ����
typedef struct {
    Point *center; // �������� �� ����� ����
    float radius;  // ����� ����
} Circle;

// ��������� ������� ��� ������ � ������
Circle *createCircle(Point *center, float radius); // ������� ��������� ����
void printCircle(Circle *c);                       // ������� ��������� ���������� ��� ����
float areaOfCircle(Circle *c);                     // ������� ���������� ����� ����
void destroyCircle(Circle *c);                     // ������� �������� ����

#endif

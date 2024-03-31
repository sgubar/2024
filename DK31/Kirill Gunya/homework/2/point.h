#ifndef POINT_H
#define POINT_H

// ��������� ��� ������������� ����� �� ��������� ������
typedef struct {
    float x; // ���������� X �����
    float y; // ���������� Y �����
} Point;

// ��������� ������� ��� ������ � �������
Point *createPoint(float x, float y); // ������� ��� ��������� ���� �����
void printPoint(Point *p);            // ������� ��� ��������� ��������� �����
void destroyPoint(Point *p);          // ������� ��� �������� ����� �� ��������� �������

#endif

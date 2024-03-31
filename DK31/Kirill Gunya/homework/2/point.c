#include "point.h"
#include <stdio.h>
#include <stdlib.h>

// ��������� ������� ��� ������ � �������
Point *createPoint(float x, float y) {
    Point *newPoint = (Point *)malloc(sizeof(Point)); // �������� ���'�� ��� ���� �����
    if (newPoint != NULL) { // ���� ���'��� ������ �������
        newPoint->x = x;    // ������ ���������� X
        newPoint->y = y;    // ������ ���������� Y
    }
    return newPoint;        // ��������� �������� �� ���� �����
}

void printPoint(Point *p) {
    if (p != NULL) { // ��������, �� ����� �� � NULL
        printf("(%f, %f)", p->x, p->y); // ���� ��������� �����
    } else {
        printf("Invalid point\n");
    }
}

void destroyPoint(Point *p) {
    free(p); // ��������� ���'��, ������� �� �����
}

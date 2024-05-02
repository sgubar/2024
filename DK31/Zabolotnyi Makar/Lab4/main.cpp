#include <windows.h>
#include <GL/glut.h> //
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>

#include "point.h"
#include "triangle.h"

// ����� �� ������ ����
char title[] = "Rotating Graph";
int curr_width = 600, curr_height = 600;

int t = 1000 / 24; // ����� ��������� ������ ������� ������� ��������� (� ������ ������� ������ 1 ����� �� 24 �����/�)
float phase_spd = 200.0f / t; // ��� ������ �� �������
float phase = 0.0f; // ��� ������ �� ��������� �����
TriangleList_s* trilist; // ��� ������ �����

// � ����� ������� ������������� display() ���� ���� ��� �� ������ ������ ��������
// ��� ��������� ����� �� ���������� ��������
void display()
{
    // ��������� ����� �� ����
    drawTriList(trilist);

    // ����� �� ��������� �����
    glFlush();
}

// �� ������� ����������� ����� t �� ���� ��������� ������� � ����������� ������
void timer_dis(int v)
{
    // ������� ����� ��� ���������� �� �����������
    glClear(GL_COLOR_BUFFER_BIT);

    // � ������ ������� ���������� ��������� �����,
    // ��������� ��������� ���� ��������� � ���� �����������
    glPushMatrix();
    glRotatef(phase, 0.0f, 0.0f, 1.0f);

    // ��������� ����� �� ����
    drawTriList(trilist);

    // ����� �� ��������� �����
    glFlush();

    // ���������� �� ���������� ����������� ���� �����
    glPopMatrix();

    // ���������� �������
    glutTimerFunc(t, timer_dis, 0);

    // ��������� ���� ������
    phase -= phase_spd;
    if (phase <= (-360)){
        phase = 0;
    }
}


int main(int argc, char* argv[])
{
    Point* points1[3];
    Point* points2[3];
    Point* points3[3];
    Point* points4[3];
    Point* points5[3];
   Triangle *triangle1, *triangle2, *triangle3, *triangle4, *triangle5;

    // �������� ������ �����
    trilist = createTriList();

    // �������� ������ � ������ �� �� ������
    points1[0] = createPoint(0, 20);
    points1[1] = createPoint(0, 5);
    points1[2] = createPoint(35, 0);
    triangle1 = createTriangle(points1, createColor(1.0, 0.9, 0.2));

    addTriToTriList(trilist, triangle1);

    points2[0] = createPoint(40, 0);
    points2[1] = createPoint(80, 0);
    points2[2] = createPoint(60, 36);
    triangle2 = createTriangle(points2, createColor(1.0, 1.0, 1.0));

    addTriToTriList(trilist, triangle2);

    points3[0] = createPoint(-30, -10);
    points3[1] = createPoint(-60, -20);
    points3[2] = createPoint(30, -60);
    triangle3 = createTriangle(points3, createColor(0.1, 0.1, 0.1));

    addTriToTriList(trilist, triangle3);

    // ������� 2 ������ � ������ �� ����
    removeTriFromTriListAtIndex(trilist, 0);

    points4[0] = createPoint(-70, 10);
    points4[1] = createPoint(-40, 20);
    points4[2] = createPoint(-60, -70);
    triangle4 = createTriangle(points4, createColor(0.0, 0.0, 1.0));

    insertTriToTriListAtIndex(trilist, 1, triangle4);

    points5[0] = createPoint(25, 90);
    points5[1] = createPoint(50, -25);
    points5[2] = createPoint(40, -80);
    triangle5 = createTriangle(points5, createColor(0.3, 0.5, 0.0));

    addTriToTriList(trilist, triangle5);

    // ���������� ���������� OpenGL
    glutInit(&argc, argv);
    // ��������� ����
    glutInitWindowSize(curr_width, curr_height);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(title);
    // �������� display �� ������� ��������� (� ������ ������� �����������)
    glutDisplayFunc(display);
    // ������ ��������� ������ ��� ����, ��� ������ ���������� ������ ���� �������
    glutTimerFunc(0, timer_dis, 0);
    // ��������� �������� ���� OpenGL
    glutMainLoop();

    return 0;
}

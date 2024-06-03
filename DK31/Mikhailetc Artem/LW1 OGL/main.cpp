#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>

#include "point.h"
#include "figure.h"

// ����� �� ������ ����
char title[] = "Rotating Graph";
int curr_width = 600, curr_height = 600;

int t = 1000 / 10; // ����� ��������� ������ ������� ������� ��������� (� ������ ������� ������ 1 ����� �� 10 ������)
float theta_spd = 360.0f / t; // ��� ������ �� �������
float theta = 0.0f; // ��� ������
FigureList_s* figlist; // ������ �����

void display()
{
    // ��������� ����� �� ����
    drawFigList(figlist);

    // ����� �� ��������� �����
    glFlush();
}

// �� ������� ����������� ����� t �� ���� ��������� ������� � ����������� ������
void timer_dis(int v)
{
    // ������� ����� ��� ���������� �� �����������
    glClear(GL_COLOR_BUFFER_BIT);

    // ���������� ��������� �����
    glPushMatrix();
    glRotatef(theta, 0.0f, 0.0f, 1.0f);

    // ��������� ����� �� ����
    drawFigList(figlist);

    // ����� �� ��������� �����
    glFlush();

    // ���������� �� ���������� ����������� ���� �����
    glPopMatrix();

    // ���������� �������
    glutTimerFunc(t, timer_dis, 0);

    // ��������� ���� ������
    theta += theta_spd;
    if (theta >= (360)){
        theta = 0;
    }
}


int main(int argc, char* argv[])
{
    Point* points1[4];
    Point* points2[4];

    Figure_s *figure1, *figure2;

    // �������� ������ �����
    figlist = createFigList();

    // �������� ������ � ������ �� �� ������
    points1[0] = createPoint(10, 50);
    points1[1] = createPoint(50, 50);
    points1[2] = createPoint(50, 10);
    points1[3] = createPoint(10, 10);
    figure1 = createFigure(points1, createColor(0.0, 0.0, 1.0));

    addFigToFigList(figlist, figure1); //������ ������ 1 �� ������
    points2[0] = createPoint(0, -40);   // ˳�� ����� �����
    points2[1] = createPoint(-80, -40); // ˳�� ������ �����
    points2[2] = createPoint(-80, 0);   // ����� ������ �����
    points2[3] = createPoint(0, 0);     // ����� ����� �����
    figure2 = createFigure(points2, createColor(0.0, 1.0, 0.0));

    addFigToFigList(figlist, figure2);

    // ���������� ���������� OpenGL
    glutInit(&argc, argv);
    // ��������� ����
    glutInitWindowSize(curr_width, curr_height);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(title);
    // �������� display �� ������� ���������
    glutDisplayFunc(display);
    // ������ ��������� ������ ��� ����, ��� ������ ���������� ������ ���� �������
    glutTimerFunc(0, timer_dis, 0);
    // ��������� �������� ���� OpenGL
    glutMainLoop();

    return 0;
}

#include <windows.h>
#include <GL/glut.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>

#include "point.h"
#include "figure.h"


char title[] = "window";
int curr_width = 600, curr_height = 600;

int t = 1000 / 24;
float theta_spd = 360.0f / t;
float theta = 0.0f;
FigureList_s* figlist;

void display()
{
    drawFigList(figlist);

    glFlush();
}

void timer_dis(int v)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glRotatef(theta, 0.0f, 0.0f, 1.0f);

    drawFigList(figlist);


    glFlush();

    glPopMatrix();

    glutTimerFunc(t, timer_dis, 0);

    theta += theta_spd;
    if (theta >= (360)) {
        theta = 0;
    }
}


int main(int argc, char* argv[])
{
    Point* points1[3];
    Point* points2[3];
    Point* points3[3];
    Point* points4[3];
    Figure_s* figure1, * figure2, * figure3, * figure4;

    figlist = createFigList();

    points1[0] = createPoint(1, 11);
    points1[1] = createPoint(1, 1);
    points1[2] = createPoint(11, 1);
    figure1 = createFigure(points1, createColor(1.0, 0.0, 1.0));

    addFigToFigList(figlist, figure1);

    points2[0] = createPoint(-88, 8);
    points2[1] = createPoint(-41, 14);
    points2[2] = createPoint(-17, -71);
    figure2 = createFigure(points2, createColor(1.0, 0.0, 1.0));

    addFigToFigList(figlist, figure2);

    points3[0] = createPoint(-33, -13);
    points3[1] = createPoint(77, -17);
    points3[2] = createPoint(66, -66);
    figure3 = createFigure(points3, createColor(1.0, 0.0, 0.1));

    addFigToFigList(figlist, figure3);

    removeFigFromFigListAtIndex(figlist, 1);

    points4[0] = createPoint(-55, 15);
    points4[1] = createPoint(-32, 23);
    points4[2] = createPoint(-54, -45);
    figure4 = createFigure(points4, createColor(1.0, 0.0, 1.0));

    insertFigToFigListAtIndex(figlist, 1, figure4);

    glutInit(&argc, argv);
    glutInitWindowSize(curr_width, curr_height);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(title);
    glutDisplayFunc(display);
    glutTimerFunc(0, timer_dis, 0);
    glutMainLoop();

    return 0;
}

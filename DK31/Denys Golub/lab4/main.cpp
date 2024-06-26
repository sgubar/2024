#include <windows.h>
#include <GL/glut.h>
#define _USE_MATH_DEFINES 
#include <math.h>
#include <stdlib.h>  // добавим для использования функции rand()

#include "point.h"
#include "square.h"

char title[] = "Rotating Square";
int curr_width = 600, curr_height = 600;

const int t = 1000 / 24;
float theta_spd = 360.0f / t;
float theta = 0.0f;
SquareList_s* rectlist;

void display() {
    drawSquareList(rectlist);
    glFlush();
}

void timer_dis(int v) {
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glRotatef(theta, 0.0f, 0.0f, 1.0f);

    // Случайным образом изменяем цвет первого квадрата в списке
    if (rectlist != NULL && rectlist->head != NULL) {
        float r = (float)rand() / (float)RAND_MAX;
        float g = (float)rand() / (float)RAND_MAX;
        float b = (float)rand() / (float)RAND_MAX;
        changeSquareColor(rectlist->head->figure, r, g, b);
    }

    drawSquareList(rectlist);
    glFlush();

    glPopMatrix();

    glutTimerFunc(t, timer_dis, 0);

    theta += theta_spd;
    if (theta >= (360)) {
        theta = 0;
    }
}

int main(int argc, char* argv[]) {
    Point* points1[4];

    Square_s* figure1;

    rectlist = createSquareList();

    points1[0] = createPoint(-15, -15);
    points1[1] = createPoint(-15, 15);
    points1[2] = createPoint(15, 15);
    points1[3] = createPoint(15, -15);

    figure1 = createSquare(points1, createColor(1.0, 1.0, 0.0));
    addSquareToSquareList(rectlist, figure1);

    glutInit(&argc, argv);
    glutInitWindowSize(curr_width, curr_height);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(title);
    glutDisplayFunc(display);
    glutTimerFunc(0, timer_dis, 0);
    glutMainLoop();

    return 0;
}

#include <GL/glut.h>

#include "list.h"

#define FPS         40
#define FRAME_T     (1000/FPS)
#define THETA_SPD   (360.0f / FPS)
float theta = 0.0f;

List *trapeziums = NULL;

void display(void) {
    drawTrapeziumsList(trapeziums);
    glFlush();
}

void timer_dis(int v) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(theta, 0.0f, 0.0f, 1.0f);

    drawTrapeziumsList(trapeziums);
    glFlush();

    glPopMatrix();
    glutTimerFunc(FRAME_T, timer_dis, 0);

    theta += THETA_SPD;
    if (theta >= (360)){
        theta = 0;
    }
}

int main(int argc, char* argv[]) {
    trapeziums = createList();

    Trapezium *tr1 = createTrapeziumFromCords(-3, -3, 5, 1, 10, -2, -4, -9, createColor(0.5, 0.1, 0.4));
    Trapezium *tr2 = createTrapeziumFromCords(2,   4, 4, 4,  5,  2,  1,  2, createColor(0.8, 0.7, 0.0));
    Trapezium *tr3 = createTrapeziumFromCords(1,   1, 2, 1,  3,  0,  0,  0, createColor(1.0, 1.0, 1.0));

    appendTrapeziumToList(trapeziums, tr1);
    appendTrapeziumToList(trapeziums, tr2);
    appendTrapeziumToList(trapeziums, tr3);

    glutInit(&argc, argv);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("6");

    glutDisplayFunc(display);
    glutTimerFunc(0, timer_dis, 0);

    glutMainLoop();

    destroyTrapezium(tr1);
    destroyTrapezium(tr2);
    destroyTrapezium(tr3);
    destroyList(trapeziums);

    return 0;
}

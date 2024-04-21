#include <GL/glut.h>
#include <math.h>

#include "my_ogl_funcs.h"

/*
 * Curve:       blue
 * Coords:      white
 * Background:  red
 */

void calculateFunc(float *x, float *y, float t) {
    const float a = 0.5;
    *x = (a * sqrt(2) * cos(t)) / (1 + pow(sin(t), 2));
    *y = (a * sqrt(2) * cos(t) * sin(t)) / (1 + pow(sin(t), 2));
}

int main(int argc, char* argv[]) {
    setCurveColor(0.0, 0.0, 1.0);
    setBackColor(1.0, 0.0, 0.0);
    setCoordsColor(1.0, 1.0, 1.0);

    setCenter(0.0, 0.0);
    setSteps(0.05, 0.01);

    attachMathFunc(&calculateFunc, -M_PI + 0.01, M_PI);

    glutInit(&argc, argv);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("6");
    glutDisplayFunc(displayFuncT);

    glutMainLoop();
    return 0;
}

#include "my_ogl_funcs.h"
#include <GL/glut.h>

#include <math.h>

Stage displayStage;

void setColor(ColorProps *props, unsigned char r, unsigned char g, unsigned char b);

void setSteps(float coordStep, float curveStep) {
    displayStage.coordStep = coordStep;
    displayStage.curveStep = curveStep;
}

void setCenter(float centerX, float centerY) {
    displayStage.centerX = centerX;
    displayStage.centerY = centerY;
}

void attachMathFunc(void (*funcPtr)(float *, float *, float), float minT, float maxT) {
    displayStage.func_t = funcPtr;

    displayStage.minT = minT;
    displayStage.maxT = maxT;
}

void setCurveColor(unsigned char r, unsigned char g, unsigned char b) {
    setColor(&displayStage.curve, r, g, b);
}


void setBackColor(unsigned char r, unsigned char g, unsigned char b) {
    setColor(&displayStage.back, r, g, b);
}


void setCoordsColor(unsigned char r, unsigned char g, unsigned char b) {
    setColor(&displayStage.coords, r, g, b);
}

void setColor(ColorProps *props, unsigned char r, unsigned char g, unsigned char b) {
    if ((r >= 0 && r <= 1) && (g >= 0 && g <= 1) && (b >= 0 && b <= 1)) {
        props->red = r;
        props->green = g;
        props->blue = b;
    }
}

void displayFuncT(void) {
    // setup background colours (with default alpha=1)
    glClearColor(displayStage.back.red, displayStage.back.green, displayStage.back.blue, 1.0f);
    // clean colour buffer
    glClear(GL_COLOR_BUFFER_BIT);

    // paint coordinates axes
    // ordinate (y)
    glBegin(GL_LINE_STRIP);
        glColor3f(displayStage.coords.red, displayStage.coords.green, displayStage.coords.blue);
        glVertex2f(displayStage.centerX, -1.0);
        glVertex2f(displayStage.centerX, 1.0);
    glEnd();

    // abscissa (x)
    glBegin(GL_LINE_STRIP);
        glColor3f(displayStage.coords.red, displayStage.coords.green, displayStage.coords.blue);
        glVertex2f(-1.0, displayStage.centerY);
        glVertex2f(1.0, displayStage.centerY);
    glEnd();

    // paint coords
    for (float x = -1.0; x <= 1.0; x += displayStage.coordStep){
        glBegin(GL_LINE_STRIP);
            glColor3f(displayStage.coords.red, displayStage.coords.green, displayStage.coords.blue);
            glVertex2f(x, displayStage.centerY - (displayStage.coordStep / 2));
            glVertex2f(x, displayStage.centerY + (displayStage.coordStep / 2));
        glEnd();
    }
    for (float y = -1.0; y <= 1.0; y += displayStage.coordStep){
        glBegin(GL_LINE_STRIP);
            glColor3f(displayStage.coords.red, displayStage.coords.green, displayStage.coords.blue);
            glVertex2f(displayStage.centerX - (displayStage.coordStep / 2), y);
            glVertex2f(displayStage.centerX + (displayStage.coordStep / 2), y);
        glEnd();
    }

    float x, y;
    glBegin(GL_LINE_STRIP);
    glColor3f(displayStage.curve.red, displayStage.curve.green, displayStage.curve.blue);
    for (float t = displayStage.minT; t <= displayStage.maxT; t += displayStage.curveStep) {
        displayStage.func_t(&x, &y, t);
        glVertex2f(displayStage.centerX + x, displayStage.centerY + y);
    }
    glEnd();

    glFlush();
}

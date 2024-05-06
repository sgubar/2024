#include "trapezium.h"

#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>

// internal functions
int isLine(Point *S, Point *E);
void lineK(Point *S, Point *E, float *m, int *i);


void lineK(Point *S, Point *E, float *m, int *i) {
    if (S->x != E->x) {
        // if line isn't parallel to Y axis
        *i = 0;
        *m = (S->y - E->y) / (S->x - E->x);
    } else {
        // if line isn't parallel to X axis
        *i = 1;
        *m = (S->x - E->x) / (S->y - E->y);
    }
}


int isLine(Point *S, Point *E) {
    return (S->x != E->x) || (S->y != E->y);
}


int validateTrapezium(Trapezium *tr) {
    if (!isLine(tr->A, tr->B)) {         // validate first line
        return 0;
    } else if (!isLine(tr->B, tr->C)) {  // validate second line
        return 0;
    } else if (!isLine(tr->C, tr->D)) {  // validate third line
        return 0;
    } else if (!isLine(tr->D, tr->A)) {  // validate fourth line
        return 0;
    }

    float mb1, mb2, ms1, ms2;
    int ib1, ib2, is1, is2;

    // first base
    lineK(tr->A, tr->B, &mb1, &ib1);

    // second base
    lineK(tr->D, tr->C, &mb2, &ib2);

    // first side
    lineK(tr->D, tr->A, &ms1, &is1);

    // second side
    lineK(tr->C, tr->B, &ms2, &is2);

    // if sides is not parallel   and      bases are parallel
    if ((is1 == is2 && ms1 != ms2) && (ib2 == ib1 && mb1 == mb2)) {
        return 1;
    } else {
        return 0;
    }

}


Trapezium *createTrapeziumFromCords(float ax, float ay, float bx, float by, float cx, float cy, float dx, float dy,  ColorProps color) {
    Trapezium *result = (Trapezium *) malloc(sizeof(Trapezium));

    // if pointer valid create points
    if (result != NULL) {
        result->A = createPoint(ax, ay);
        result->B = createPoint(bx, by);
        result->C = createPoint(cx, cy);
        result->D = createPoint(dx, dy);

        result->color = color;
    }

    return result;
}


void destroyTrapezium(Trapezium *tr) {
    if (tr != NULL) {
        destroyPoint(tr->A);
        destroyPoint(tr->B);
        destroyPoint(tr->C);
        destroyPoint(tr->D);
        free(tr);
    }
}


ColorProps createColor(float red, float green, float blue) {
    ColorProps res = {red, green, blue};

    return res;
}


void drawTrapezium(Trapezium *tr) {
    if (NULL != tr) {
        glBegin(GL_POLYGON);
        glColor3f(tr->color.red, tr->color.green, tr->color.blue);
        glVertex2f(tr->A->x / 10.0f, tr->A->y / 10.0f);
        glVertex2f(tr->B->x / 10.0f, tr->B->y / 10.0f);
        glVertex2f(tr->C->x / 10.0f, tr->C->y / 10.0f);
        glVertex2f(tr->D->x / 10.0f, tr->D->y / 10.0f);
        glEnd();
    }
}

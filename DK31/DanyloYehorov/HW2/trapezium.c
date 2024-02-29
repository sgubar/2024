#include "trapezium.h"
#include <stdlib.h>
#include <stdio.h>


// internal functions
void readCords(float *x, float *y, char pointName);
float modulus(float a);
int isLine(Point *S, Point *E);
void lineK(Point *S, Point *E, float *m, int *i);


Trapezium * getTrapezium() {
    printf(" Enter cords of trapezium\n"
           "    A ____ B             \n"
           "     /    \\             \n"
           "    /      \\            \n"
           " D /--------\\ C         \n\n");

    float ax, ay, bx, by, cx, cy, dx, dy;
    Trapezium *tr = createTrapeziumFromCords(0, 0, 0, 0, 0, 0, 0, 0);
    do {
        destroyTrapezium(tr);
        putchar('\n');
        readCords(&ax, &ay, 'A');
        readCords(&bx, &by, 'B');
        readCords(&cx, &cy, 'C');
        readCords(&dx, &dy, 'D');
        tr = createTrapeziumFromCords(ax, ay, bx, by, cx, cy, dx, dy);

        if (tr == NULL) {
            printf("Can't create trapezium!\n");
            return NULL;
        }
    } while (!validateTrapezium(tr));

    return tr;
}



float modulus(float a) {
    if (a < 0) {
        return -a;
    } else {
        return a;
    }
}



void readCords(float *x, float *y, char pointName) {
    printf("Enter cords for %c: ", pointName);  // print prompt
    scanf("%f %f", x, y);                       // read coordinate
    while (getchar() != '\n');                  // clean the input buffer
}



void printTrapeziumPoints(Trapezium *tr) {
    printf("A point: ");
    printPoint(tr->A);
    printf("\nB point: ");
    printPoint(tr->B);
    printf("\nC point: ");
    printPoint(tr->C);
    printf("\nD point: ");
    printPoint(tr->D);
    printf("\n");
}



float areaOfTrapezium(Trapezium *tr) {
    float result = 0.5 * modulus((tr->A->x * tr->B->y - tr->B->x * tr->A->y) +
                                 (tr->B->x * tr->C->y - tr->C->x * tr->B->y) +
                                 (tr->C->x * tr->D->y - tr->D->x * tr->C->y) +
                                 (tr->D->x * tr->A->y - tr->A->x * tr->D->y));
    return result;
}



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

    // if if sides not parallel   and      bases are parallel
    if ((is1 != is2 || ms1 != ms2) && (ib2 == ib1 && mb1 == mb2)) {
        return 1;
    } else {
        return 0;
    }

}



Trapezium *createTrapeziumFromArray(Point points[]) {
    return createTrapeziumFromCords(points[0].x, points[0].y, points[1].x, points[1].y, points[2].x, points[2].y, points[3].x, points[3].y);
}



Trapezium *createTrapeziumFromPtrArray(Point *points[]) {
    // check points pointer
    if (points == NULL) {
        return NULL;
    }

    return createTrapeziumFromCords(points[0]->x, points[0]->y, points[1]->x, points[1]->y, points[2]->x, points[2]->y, points[3]->x, points[3]->y);
}



Trapezium *createTrapeziumFromCords(float ax, float ay, float bx, float by, float cx, float cy, float dx, float dy) {
    Trapezium *result = (Trapezium *) malloc(sizeof(Trapezium));

    // if pointer valid create points
    if (result != NULL) {
        result->A = createPoint(ax, ay);
        result->B = createPoint(bx, by);
        result->C = createPoint(cx, cy);
        result->D = createPoint(dx, dy);
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

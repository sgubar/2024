#include "geometry.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Функція для створення трикутника
Triangle* create_triangle(Point* point1, Point* point2, Point* point3) {
    Triangle* triangle = (Triangle*)malloc(sizeof(Triangle));
    if (triangle == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    triangle->points[0] = point1;
    triangle->points[1] = point2;
    triangle->points[2] = point3;
    return triangle;
}

// Функція для знищення трикутника
void destroy_triangle(Triangle* triangle) {
    free(triangle);
}

// Функція для обчислення площі трикутника
double calculate_triangle_area(Triangle* triangle) {
    double a, b, c, s;

    a = sqrt(pow(triangle->points[1]->x - triangle->points[0]->x, 2) +
             pow(triangle->points[1]->y - triangle->points[0]->y, 2));
    b = sqrt(pow(triangle->points[2]->x - triangle->points[1]->x, 2) +
             pow(triangle->points[2]->y - triangle->points[1]->y, 2));
    c = sqrt(pow(triangle->points[0]->x - triangle->points[2]->x, 2) +
             pow(triangle->points[0]->y - triangle->points[2]->y, 2));

    s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// Функція для виводу параметрів трикутника
void print_triangle(Triangle* triangle) {
    printf("Triangle vertices:\n");
    for (int i = 0; i < 3; i++) {
        printf("Vertex %d: (%lf, %lf)\n", i+1, triangle->points[i]->x, triangle->points[i]->y);
    }
}


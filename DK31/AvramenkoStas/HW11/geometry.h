#ifndef GEOMETRY_H
#define GEOMETRY_H

// Опис структури точки
typedef struct {
    double x;
    double y;
} Point;

// Опис структури трикутника
typedef struct {
    Point* points[3];
} Triangle;

// Функції для обробки трикутників
Triangle* create_triangle(Point* point1, Point* point2, Point* point3);
void destroy_triangle(Triangle* triangle);
double calculate_triangle_area(Triangle* triangle);
void print_triangle(Triangle* triangle);

#endif



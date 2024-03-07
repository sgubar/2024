#include "geometry.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Створення точок
    Point* point1 = (Point*)malloc(sizeof(Point));
    Point* point2 = (Point*)malloc(sizeof(Point));
    Point* point3 = (Point*)malloc(sizeof(Point));

    if (point1 == NULL || point2 == NULL || point3 == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    // Введення координат точок з клавіатури
    printf("Enter coordinates for point 1 (x y): ");
    scanf("%lf %lf", &point1->x, &point1->y);

    printf("Enter coordinates for point 2 (x y): ");
    scanf("%lf %lf", &point2->x, &point2->y);

    printf("Enter coordinates for point 3 (x y): ");
    scanf("%lf %lf", &point3->x, &point3->y);

    // Створення трикутника
    Triangle* triangle = create_triangle(point1, point2, point3);

    // Вивід параметрів трикутника
    print_triangle(triangle);

    // Обчислення та вивід площі трикутника
    double area = calculate_triangle_area(triangle);
    printf("Triangle area: %lf\n", area);

    // Знищення трикутника
    destroy_triangle(triangle);

    // Звільнення пам'яті
    free(point1);
    free(point2);
    free(point3);

    return 0;
}


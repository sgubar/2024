#include <stdio.h>
#include "circle.h"
#include "point.h"

int main() {
    // Запрос у користувача координат центра та радіуса кола
    float x, y, radius;
    printf("Enter the coordinates of the center of the circle (x y): ");
    scanf("%f %f", &x, &y);
    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);

    // Створення центру кола
    // Point *center = createPoint(x, y); // Створення нової точки
    Point center = {0,0};
    // if (center == NULL) {
    //     printf("Failed to create center of circle.\n");
    //     return 1; // Завершення програми з кодом помилки
    // }

    // Створення кола з заданим центром і радіусом
    Circle *circle = createCircle(&center, radius);
    if (circle == NULL) {
        printf("Failed to create circle.\n");
        // destroyPoint(center); // Звільняємо пам'ять, виділену для центру
        return 1; // Завершення програми з кодом помилки
    }

    // Виведення інформації про коло та його площу
    printCircle(circle);
    printf("Circle area: %.2f\n", areaOfCircle(circle));

    // Знищення кола та звільнення ресурсів
    destroyCircle(circle);

    return 0; // Успішне завершення програми
}

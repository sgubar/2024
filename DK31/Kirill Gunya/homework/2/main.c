#include <stdio.h>
#include "circle.h"
#include "point.h"

int main() {
    // ������ � ����������� ��������� ������ �� ������ ����
    float x, y, radius;
    printf("Enter the coordinates of the center of the circle (x y): ");
    scanf("%f %f", &x, &y);
    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);

    // ��������� ������ ����
    // Point *center = createPoint(x, y); // ��������� ���� �����
    Point center = {0,0};
    // if (center == NULL) {
    //     printf("Failed to create center of circle.\n");
    //     return 1; // ���������� �������� � ����� �������
    // }

    // ��������� ���� � ������� ������� � �������
    Circle *circle = createCircle(&center, radius);
    if (circle == NULL) {
        printf("Failed to create circle.\n");
        // destroyPoint(center); // ��������� ���'���, ������� ��� ������
        return 1; // ���������� �������� � ����� �������
    }

    // ��������� ���������� ��� ���� �� ���� �����
    printCircle(circle);
    printf("Circle area: %.2f\n", areaOfCircle(circle));

    // �������� ���� �� ��������� �������
    destroyCircle(circle);

    return 0; // ������ ���������� ��������
}

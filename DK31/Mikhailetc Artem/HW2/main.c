#include <stdio.h>
#include "point.h"
#include "rect.h"

int main() {
    Point point1 = {2.0, 4.0};
    Point point2 = {6.0, 1.0};
    
    Point points[2] = {point1, point2};
    
    Rectangle* rectangle = createRectangle(points, 2);
    if (rectangle != NULL) {
        printRectangle(rectangle);
        
        printf("Площа прямокутника: %f\n", calculateArea(rectangle));
        
        destroyRectangle(rectangle);
    }
    
    return 0;
}

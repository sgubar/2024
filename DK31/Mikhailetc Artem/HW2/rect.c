#include "rect.h"
#include <stdio.h>
#include <stdlib.h> 

Rectangle* createRectangle(Point* points, int size) {
    if (size != 2) {
        printf("Потрібно передати дві точки для створення прямокутника.\n");
        return NULL;
    }
    
    Rectangle* rect = (Rectangle*)malloc(sizeof(Rectangle)); 
    if (rect == NULL) {
        printf("Не вдалося виділити пам'ять для прямокутника.\n");
        return NULL;
    }
    
    rect->topLeft = points[0];
    rect->bottomRight = points[1];
    
    return rect;
}

void destroyRectangle(Rectangle* rect) {
    free(rect);
}

double calculateArea(Rectangle* rect) {
    double width = rect->bottomRight.x - rect->topLeft.x;
    double height = rect->topLeft.y - rect->bottomRight.y;
    return width * height;
}

void printRectangle(Rectangle* rect) {
    printf("Прямокутник з точками (%f, %f) і (%f, %f)\n", 
           rect->topLeft.x, rect->topLeft.y, rect->bottomRight.x, rect->bottomRight.y);
}

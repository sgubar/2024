#include "rectangle.h"
#include <stdio.h>
#include <stdlib.h>

Rectangle* createRectangle(double x1, double y1, double x2, double y2) {
    Rectangle* rect = (Rectangle*)malloc(sizeof(Rectangle));
    if (rect == NULL) {
        printf("Не вдалося виділити пам'ять для прямокутника.\n");
        return NULL;
    }
    
    rect->topLeft.x = x1;
    rect->topLeft.y = y1;
    rect->bottomRight.x = x2;
    rect->bottomRight.y = y2;
    
    return rect;
}

void destroyRectangle(Rectangle* rect) {
    free(rect);
}

void printRectangle(Rectangle* rect) {
    printf("Прямокутник з точками (%.2f, %.2f) і (%.2f, %.2f)\n", 
           rect->topLeft.x, rect->topLeft.y, rect->bottomRight.x, rect->bottomRight.y);
}

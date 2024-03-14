#include "rect.h"
#include <stdlib.h>
#include <string.h>

Rectangle *create_Rectangle(Point *A, Point *C) {
  Rectangle *result = (Rectangle *)malloc(sizeof(Rectangle)); //виділяємо пам'ять для структури

  if (NULL != result) { //перевірка чи result не нуль
    result->A = createPoint(A->x, A->y); //нова точка, яка копіює координати вершини A
    result->C = createPoint(C->x, C->y); //нова точка, яка копіює координати вершини В
  }

  return result;
}

void destroyRectangle(Rectangle *R) {
  if (NULL == R) { //перевірка чи R не нуль
    return;
  }

  destroyPoint(R->A); //видаляємо точку А
  destroyPoint(R->C); //видаляємо точку В

  free(R); //звільнюємо пам'ять структури
}

double calculateRectangleArea(Rectangle *R) //Обчислюємо площу
{
    double width = R->A->x - R->C->x;
    double height = R->A->y - R->C->y;
    double area =width*height; 
    return area; 
}

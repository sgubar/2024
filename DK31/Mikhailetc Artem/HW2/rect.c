#include "rect.h"
#include <stdlib.h>
#include <string.h>

Rectangle *create_Rectangle(Point *A, Point *C) {
  Rectangle *result = (Rectangle *)malloc(sizeof(Rectangle)); 

  if (NULL != result) 
    result->A = createPoint(A->x, A->y); 
    result->C = createPoint(C->x, C->y); 
  }

  return result;
}

void destroyRectangle(Rectangle *R) {
  if (NULL == R) {
    return;
  }

  destroyPoint(R->A);
  destroyPoint(R->C);

  free(R); 
}

double calculateRectangleArea(Rectangle *R)
{
    double width = R->A->x - R->C->x;
    double height = R->A->y - R->C->y;
    double area =width*height; 
    return area; 
}

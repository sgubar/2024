#include "rect.h"
#include <stdlib.h>
#include <string.h>

Rectangle *create_Rectangle(void) {
  Rectangle *result = (Rectangle *)malloc(sizeof(Rectangle));

  if (NULL != result) {
    result->A = NULL;
    result->C = NULL;
  }

//	memset(result, 0, sizeof(Rectangle));
//bzero(result, sizeof(Rectangle));

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

double calculateRectangleArea(Rectangle *R) {  //Обчислює площу прямокутника за допомогою координат його верхньої лівої та нижньої правої точок
    double width = R->A->x - R->C->x;
    double height = R->A->y - R->C->y;
    double area =width*height; 
   printf("Площа прямокутника: %.2f\n", area);
    return area; 
}

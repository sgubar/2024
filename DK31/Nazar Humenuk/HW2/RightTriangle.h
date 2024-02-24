#ifndef RightTriangle_h
#define RightTriangle_h

#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include <math.h>

void zadati_kord(Point *aPoint, Point *bPoint, Point *cPoint);//Функція отримання кординат у точки від користувача

typedef struct tagRightTriangle{// створення структири для трикутниками з точками
  Point *p1;
  Point *p2;
  Point *p3;
  
}RTrgle;//назва визову структури трикутника

RTrgle *crateRightTriangle(float ax, float ay, float bx, float by, float cx, float cy);// функція створення трикутника за координатами

RTrgle *crateRightTrianglePoint(Point *p1, Point *p2, Point *p3);// функція створення трикутника за точками

RTrgle *crateRightTriangleByMassivePoints(Point points[]);// функція створення трикутника за масивом точок

void destroyRightTriangle(RTrgle *aRTrgle);//функція видалення трикутника

void printRightTriangle(RTrgle *aRTrgle);//функція виводу трикутника

double areaRightTriangle(RTrgle *aRTrgle);// фунція визначення площі трикутника 


#endif 
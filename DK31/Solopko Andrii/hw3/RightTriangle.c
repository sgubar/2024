#include "RightTriangle.h"
#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include <cs50.h>


float InvSqrt(float x) {//Функція кореню
    if (x < 0) {
        // Обробка випадку, коли аргумент від'ємний (результат невизначений у дійсних числах)
        printf("Помилка: квадратний корінь з від'ємного числа невизначений у дійсних числах\n");
        return 0.0; // Або будь-яке інше значення за вашим вибором
    }

    float epsilon = 0.00001; // Точність (помилка)
    float guess = x; // Початкове наближення

    while ((guess * guess - x) > epsilon) {//Цикл обчислення кореню
        guess = (guess + x / guess) / 2.0;
    }

    return guess;//повертаємо корінь числа
}

void zadati_kord(Point *aPoint, Point *bPoint, Point *cPoint){//Функція отримання кординат у точки від користувача
  Point *center = createPoint(0, 0) ;//створюємо точку центра гіпотинузи , та кола 
  printf(" Задайте кординати точок прямокутного трикутника x, y");
  printf("\n1 точка 1 кордината: ");
  while (scanf("%f", &aPoint->x) != 1) {//перевірка на правильність введення
      printf("Некоректне значення. Будь ласка, введіть число: ");
      while (getchar() != '\n'); // Очищення буфера введення
  }
  printf("\n1 точка 2 кордината: ");
  while (scanf("%f", &aPoint->y) != 1) {
      printf("Некоректне значення. Будь ласка, введіть число: ");
      while (getchar() != '\n'); // Очищення буфера введення
  }
  printf("\n2 точка 1 кордината: ");
  while (scanf("%f", &bPoint->x) != 1) {
      printf("Некоректне значення. Будь ласка, введіть число: ");
      while (getchar() != '\n'); // Очищення буфера введення
  }
  printf("\n2 точка 2 кордината: ");
  while (scanf("%f", &bPoint->y) != 1 || (bPoint->x == aPoint->x && bPoint->y == aPoint->y)) {//перевірка на правильність введення та на точи точки не одинакові
      printf("Некоректне значення. Будь ласка, введіть число не рівне кординатам 1 точки: ");
      while (getchar() != '\n'); // Очищення буфера введення
  }
  center->x = (aPoint->x +bPoint->x)/2;// знаходимо центр відрізка , створеного введеними координатами
  center->y = (aPoint->y +bPoint->y)/2;

  float *Radiuse = (float *)malloc(3 * sizeof(float)); // виділяємо память для радіуса
  *Radiuse = InvSqrt(pow(aPoint->x - center->x , 2) + pow(aPoint->y - center->y , 2));// надаємо значеня радіусу за допомогою модуля вектора від радіуса
  printf("3 точка 1 кордината( %f < x < %f): ", center->x - *Radiuse, *Radiuse + center->x);
  while (scanf("%f", &cPoint->x) != 1 || cPoint->x < center->x - *Radiuse || cPoint->x > center->x + *Radiuse || cPoint->x == bPoint->x || cPoint->x == aPoint->x) {// перевіка на првильність , та на то що координата попадає в діапазон , та не дорівнює кординатам x попередніх точок
      printf("Некоректне значення. Будь ласка, введіть число у вказаному діапазоні та не рівне кординатам перших точок : ");
      while (getchar() != '\n'); // Очищення буфера введення
  }
  cPoint->y = InvSqrt(pow(*Radiuse,2) - pow(cPoint->x - center->x , 2 )) + center->y ;// надаємо значення координаті y за допомогою формули виведної з рівняння кола 
  printf("3 точка 2 кордината : %f\n", cPoint->y);
  destroiPoint(center);//очичення від точки центра
  free(Radiuse);// очищення від значення радіуса

}

RTrgle *crateRightTriangle(float ax, float ay, float bx, float by, float cx, float cy){// функція створення трикутника за координатами
   RTrgle *result = (RTrgle *)malloc(sizeof(RTrgle));//виділяємо память на трикутник

   if(NULL != result){
      result->p1 = createPoint(ax , ay) ;//перевірка на існування точок
      result->p2 = createPoint(bx , by) ;
      result->p3 = createPoint(cx , cy) ;
   }
  return result;//вертаємо трикуткник
}



RTrgle *crateRightTrianglePoint(Point *p1, Point *p2, Point *p3){// функція створення трикутника за точками
   RTrgle *result = (RTrgle *)malloc(sizeof(RTrgle));//виділяємо память на трикутник

   if(NULL == p1 || NULL == p2 || NULL == p3){//перевірка на існування точок
      return NULL;
   }
  return crateRightTriangle(p1->x, p1->y, p2->x, p2->y, p3->x, p3->y);//вертаємо трикутник з викоританням функції створення трикутника за координатами
}

RTrgle *crateRightTriangleByMassivePoints(Point points[]){// функція створення трикутника за масивом точок
  RTrgle *result = (RTrgle *)malloc(sizeof(RTrgle));//виділяємо память на трикутник
  if(NULL == points){// перевірка на існування масиву точок
    return NULL;
  }
  return crateRightTrianglePoint(&points[0],&points[1],&points[2]);//вертаємо трикутник з викоританням функції створення трикутника тачками
}

void destroyRightTriangle(RTrgle *aRTrgle){//функція видалення трикутника
  if (NULL == aRTrgle){
    return;
  }

  destroiPoint(aRTrgle->p1);//видалення точок
  destroiPoint(aRTrgle->p2);
  destroiPoint(aRTrgle->p3);
  free(aRTrgle);//звільнення від трикутника

}

void printRightTriangle(RTrgle *aRTrgle){//функція виводу трикутника
  if (NULL == aRTrgle){
    return;//перевірка на існування трикутника
  }
  printf("\nP1: ");
  printPoint(aRTrgle->p1);// виведення кооординат точок
  printf("P2: ");
  printPoint(aRTrgle->p2);
  printf("P3: ");
  printPoint(aRTrgle->p3);
}

double areaRightTriangle(RTrgle *aRTrgle){// фунція визначення площі трикутника 
  if (NULL == aRTrgle){
    return -1;
  }
 return 0.5 * (InvSqrt(pow(aRTrgle->p1->x - aRTrgle->p3->x , 2) + pow(aRTrgle->p1->y - aRTrgle->p3->y , 2))*InvSqrt(pow(aRTrgle->p2->x - aRTrgle->p3->x , 2) + pow(aRTrgle->p2->y - aRTrgle->p3->y , 2)));//визначення площі трикутника за допогою множення двох катетів трикутника , які отримуються з модулів їхніх векторів
}
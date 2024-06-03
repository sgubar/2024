#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>

#include "point.h"
#include "figure.h"

// Назва та розміри вікна
char title[] = "Rotating Graph";
int curr_width = 600, curr_height = 600;

int t = 1000 / 10; // Період обертання фігури навколо початку координат (в даному прикладі робимо 1 оберт за 10 секунд)
float theta_spd = 360.0f / t; // Кут оберту між кадрами
float theta = 0.0f; // Кут оберту
FigureList_s* figlist; // Список фігур

void display()
{
    // Малювання фігур по одній
    drawFigList(figlist);

    // Запит на малювання сцени
    glFlush();
}

// Ця функція викликається через t мс після увімкнення таймеру і перемальовує фігури
void timer_dis(int v)
{
    // Очищуємо буфер щоб зображення не накладалися
    glClear(GL_COLOR_BUFFER_BIT);

    // Виконується обертання сцени
    glPushMatrix();
    glRotatef(theta, 0.0f, 0.0f, 1.0f);

    // Малювання фігур по одній
    drawFigList(figlist);

    // Запит на малювання сцени
    glFlush();

    // Повернення до початкових налаштувань виду сцени
    glPopMatrix();

    // Перезапуск таймера
    glutTimerFunc(t, timer_dis, 0);

    // Оновлення кута оберту
    theta += theta_spd;
    if (theta >= (360)){
        theta = 0;
    }
}


int main(int argc, char* argv[])
{
    Point* points1[4];
    Point* points2[4];

    Figure_s *figure1, *figure2;

    // Створимо список фігур
    figlist = createFigList();

    // Створимо фігури і додамо їх до списку
    points1[0] = createPoint(10, 50);
    points1[1] = createPoint(50, 50);
    points1[2] = createPoint(50, 10);
    points1[3] = createPoint(10, 10);
    figure1 = createFigure(points1, createColor(0.0, 0.0, 1.0));

    addFigToFigList(figlist, figure1); //Додаємо фігуру 1 до списку
    points2[0] = createPoint(0, -40);   // Ліва нижня точка
    points2[1] = createPoint(-80, -40); // Ліва верхня точка
    points2[2] = createPoint(-80, 0);   // Права верхня точка
    points2[3] = createPoint(0, 0);     // Права нижня точка
    figure2 = createFigure(points2, createColor(0.0, 1.0, 0.0));

    addFigToFigList(figlist, figure2);

    // Ініціалізуємо середовище OpenGL
    glutInit(&argc, argv);
    // Створюємо вікно
    glutInitWindowSize(curr_width, curr_height);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(title);
    // Реєструємо display як функцію малювання
    glutDisplayFunc(display);
    // Одразу запускаємо таймер для того, щоб фігури обертались одразу після запуску
    glutTimerFunc(0, timer_dis, 0);
    // Запускаємо головний цикл OpenGL
    glutMainLoop();

    return 0;
}

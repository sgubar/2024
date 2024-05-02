#include <windows.h>
#include <GL/glut.h> //
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>

#include "point.h"
#include "triangle.h"

// Назва та розміри вікна
char title[] = "Rotating Graph";
int curr_width = 600, curr_height = 600;

int t = 1000 / 24; // Період обертання фігури навколо початку координат (в даному прикладі робимо 1 оберт за 24 кадри/с)
float phase_spd = 200.0f / t; // Кут оберту між кадрами
float phase = 0.0f; // Кут оберту як глобальна змінна
TriangleList_s* trilist; // Наш список фігур

// В цьому прикладі викликатимемо display() лише один раз на почаку роботи програми
// для малювання фігур на початкових позиціях
void display()
{
    // Малювання фігур по одній
    drawTriList(trilist);

    // Запит на малювання сцени
    glFlush();
}

// Ця функція викликається через t мс після увімкнення таймеру і перемальовує фігури
void timer_dis(int v)
{
    // Очищуємо буфер щоб зображення не накладалися
    glClear(GL_COLOR_BUFFER_BIT);

    // В нашому прикладі виконується обертання сцени,
    // параметри обертання буде покладено в стек перетворень
    glPushMatrix();
    glRotatef(phase, 0.0f, 0.0f, 1.0f);

    // Малювання фігур по одній
    drawTriList(trilist);

    // Запит на малювання сцени
    glFlush();

    // Повернення до початкових налаштувань виду сцени
    glPopMatrix();

    // Перезапуск таймера
    glutTimerFunc(t, timer_dis, 0);

    // Оновлення кута оберту
    phase -= phase_spd;
    if (phase <= (-360)){
        phase = 0;
    }
}


int main(int argc, char* argv[])
{
    Point* points1[3];
    Point* points2[3];
    Point* points3[3];
    Point* points4[3];
    Point* points5[3];
   Triangle *triangle1, *triangle2, *triangle3, *triangle4, *triangle5;

    // Створимо список фігур
    trilist = createTriList();

    // Створимо фігури і додамо їх до списку
    points1[0] = createPoint(0, 20);
    points1[1] = createPoint(0, 5);
    points1[2] = createPoint(35, 0);
    triangle1 = createTriangle(points1, createColor(1.0, 0.9, 0.2));

    addTriToTriList(trilist, triangle1);

    points2[0] = createPoint(40, 0);
    points2[1] = createPoint(80, 0);
    points2[2] = createPoint(60, 36);
    triangle2 = createTriangle(points2, createColor(1.0, 1.0, 1.0));

    addTriToTriList(trilist, triangle2);

    points3[0] = createPoint(-30, -10);
    points3[1] = createPoint(-60, -20);
    points3[2] = createPoint(30, -60);
    triangle3 = createTriangle(points3, createColor(0.1, 0.1, 0.1));

    addTriToTriList(trilist, triangle3);

    // Замінимо 2 фігуру в списку на іншу
    removeTriFromTriListAtIndex(trilist, 0);

    points4[0] = createPoint(-70, 10);
    points4[1] = createPoint(-40, 20);
    points4[2] = createPoint(-60, -70);
    triangle4 = createTriangle(points4, createColor(0.0, 0.0, 1.0));

    insertTriToTriListAtIndex(trilist, 1, triangle4);

    points5[0] = createPoint(25, 90);
    points5[1] = createPoint(50, -25);
    points5[2] = createPoint(40, -80);
    triangle5 = createTriangle(points5, createColor(0.3, 0.5, 0.0));

    addTriToTriList(trilist, triangle5);

    // Ініціалізуємо середовище OpenGL
    glutInit(&argc, argv);
    // Створюємо вікно
    glutInitWindowSize(curr_width, curr_height);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(title);
    // Реєструємо display як функцію малювання (в нашому прикладі початкового)
    glutDisplayFunc(display);
    // Одразу запускаємо таймер для того, щоб фігури обертались одразу після запуску
    glutTimerFunc(0, timer_dis, 0);
    // Запускаємо головний цикл OpenGL
    glutMainLoop();

    return 0;
}

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#define _USE_MATH_DEFINES
#include <math.h>

void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Задаємо білий фон
    glClear(GL_COLOR_BUFFER_BIT); // Очищення буферу кольору

    // Малюємо графіки
    glBegin(GL_LINE_STRIP); // Кожна пара вершини задає відрізок
        glColor3f(1.0f, 0.0f, 0.0f);// Червоний колір
       for (float t = -M_PI; t <= M_PI; t += 0.01) {
           //будуємо графік
    float x = 1*cos(t)*cos(t) - 2 * cos(t); 
    float y = 1*sin(t)*cos(t) - 2 * cos(t);
    glVertex2f(x, y);
  }
    glEnd();

    // Малювання координатних осей
    glBegin(GL_LINE_STRIP);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(0.0, -1.0);
        glVertex2f(0.0, 1.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(-1.0, 0.0);
        glVertex2f(1.0, 0.0);
    glEnd();

    // Малювання позначок на координатних осях
    for( float x = -1.0; x <= 1.0; x += 0.1){
        glBegin(GL_LINE_STRIP);
            glColor3f(0.0f, 1.0f, 0.0f);
            glVertex2f(x, -0.05);
            glVertex2f(x, 0.05);
        glEnd();
    }
    for( float y = -1.0; y <= 1.0; y += 0.1){
        glBegin(GL_LINE_STRIP);
            glColor3f(0.0f, 1.0f, 0.0f);
            glVertex2f(-0.05, y);
            glVertex2f(0.05, y);
        glEnd();
    }
    glFlush(); // Виконати малювання
}

/* Program entry point */

int main(int argc, char* argv[])
{
    glutInit(&argc, argv); // Ініціалізація GLUT
    glutInitWindowSize(400, 400); // Ширина та висота вікна
    glutInitWindowPosition(0, 0); // Положення вікна
    glutCreateWindow("Test"); // Створення вікна із заданим ім'ям
    glutDisplayFunc(display); // Реєстрація функції зворотного виклику для малювання вікна
    glutMainLoop(); // Вхід у цикл обробки подій GLUT
return 0;
}

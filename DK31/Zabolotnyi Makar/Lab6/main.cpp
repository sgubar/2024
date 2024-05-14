#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#define _USE_MATH_DEFINES
#include <math.h>

// Функція, що викликатиметься для малювання сцени
void display()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Фон чорний (по завданню білий, але на білому фоні майже нічого не видно)
    glClear(GL_COLOR_BUFFER_BIT); // Очищення буферу кольору

    // Малювання серії відрізків, що є графіком функції
    glBegin(GL_LINE_STRIP); // Кожна пара вершини задає відрізок
        glColor3f(0.0f, 0.0f, 1.0f); // Синій колір
        for (float t = 0; t <= 4*M_PI; t += 0.1) {
            float x = (2+cos(5*t/2))*cos(t);
            float y = (2+cos(5*t/2))*sin(t);
            glVertex2f(x/10, y/10);// Був зробдений масштаб для наглядного розгляднення функцій
        }
    glEnd();

    // Малювання координатних осей
    glBegin(GL_LINE_STRIP);
        glColor3f(0.0f, 1.0f, 0.0f);// Зелений колір
        glVertex2f(0.0, -1.0);
        glVertex2f(0.0, 1.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
        glColor3f(0.0f, 1.0f, 0.0f);// Зелений колір
        glVertex2f(-1.0, 0.0);
        glVertex2f(1.0, 0.0);
    glEnd();

    // Малювання позначок на координатних осях
    for( float x = -1.0; x <= 1.0; x += 0.05){
        glBegin(GL_LINE_STRIP);
            glColor3f(0.0f, 1.0f, 0.0f);// Зелений колір
            glVertex2f(x, -0.03);
            glVertex2f(x, 0.03);
        glEnd();
    }
    for( float y = -1.0; y <= 1.0; y += 0.05){
        glBegin(GL_LINE_STRIP);
            glColor3f(0.0f, 1.0f, 0.0f);// Зелений колір
            glVertex2f(-0.03, y);
            glVertex2f(0.03, y);
        glEnd();
    }
    glFlush(); // Виконати малювання
}


int main(int argc, char* argv[])
{
    glutInit(&argc, argv); // Ініціалізація GLUT
    glutInitWindowSize(1000, 1000); // Ширина та висота вікна
    glutInitWindowPosition(0, 0); // Положення вікна
    glutCreateWindow("Dreadnot"); // Створення вікна із заданим ім'ям
    glutDisplayFunc(display); // Реєстрація функції зворотного
    // виклику для малювання вікна
    glutMainLoop(); // Вхід у цикл обробки подій GLUT
return 0;
}

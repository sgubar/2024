#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#define _USE_MATH_DEFINES
#include <math.h>

// Функція, що викликатиметься для малювання сцени
void display() {
    float a = 0.05;
    
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f); // Фон червоний та прозорий
    glClear(GL_COLOR_BUFFER_BIT); // Очищення буферу кольору

    // Малювання серії відрізків, що є графіком функції
    glBegin(GL_LINE_STRIP); // Кожна пара вершини задає відрізок
        glColor3f(1.0f, 1.0f, 0.0f); // Жовтий колір
        for (float t = 0; t <= 5*M_PI; t += 0.1) {
            float y = a*t*sin(t);
            float x = a*t*cos(t);
            glVertex2f(x, y);
        }
    glEnd();

    // Малювання координатних осей
    glBegin(GL_LINE_STRIP);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(0.0, -1.0);
        glVertex2f(0.0, 1.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(-1.0, 0.0);
        glVertex2f(1.0, 0.0);
    glEnd();

    // Малювання позначок на координатних осях
    for( float x = -1.0; x <= 1.0; x += 0.1){
        glBegin(GL_LINE_STRIP);
            glColor3f(0.0f, 0.0f, 1.0f);
            glVertex2f(x, -0.05);
            glVertex2f(x, 0.05);
        glEnd();
    }
    for( float y = -1.0; y <= 1.0; y += 0.1){
        glBegin(GL_LINE_STRIP);
            glColor3f(0.0f, 0.0f, 1.0f);
            glVertex2f(-0.05, y);
            glVertex2f(0.05, y);
        glEnd();
    }
    glFlush(); // Виконати малювання
}

/* Program entry point */

int main(int argc, char* argv[]) {
    glutInit(&argc, argv); // Ініціалізація GLUT
    glutInitWindowSize(400, 400); // Ширина та висота вікна
    glutInitWindowPosition(0, 0); // Положення вікна
    glutCreateWindow("12"); // Створення вікна із заданим ім'ям
    glutDisplayFunc(display); // Реєстрація функції зворотного
    // виклику для малювання вікна
    glutMainLoop(); // Вхід у цикл обробки подій GLUT
return 0;
}
